#include "mutex"
#include "vector"
#include "helper.h"
#include "unistd.h"
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include "unordered_map"
#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include "unordered_map"
#include "utility"
#include "keyvaluepackage.grpc.pb.h"
#include <iterator>
#include <set>
std::unordered_map<std::string,std::string> cache;
using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerCompletionQueue;
using grpc::ServerContext;
using grpc::Status;

using keyvaluepackage::KV;
using keyvaluepackage::GetKeyRequest;
using keyvaluepackage::Reply;
using keyvaluepackage::PutKeyRequest;
using keyvaluepackage::DelKeyRequest;
std::mutex door;
std::unordered_map<std::string,std::pair<int,std::string>> keyFeqValue;
std::set<std::pair<int,std::string>> feqKeq;
int NUM_OF_RECORD;

class ServerImpl final {
public:
    ~ServerImpl() {
        server_->Shutdown();
        // Always shutdown the completion queue after the server.
        cq_[0]->Shutdown();
    }
    void Run(struct conf configData) {
        NUM_OF_RECORD=configData/512;
        std::string server_address("0.0.0.0:"+ std::to_string(configData.port));

        ServerBuilder builder;
        // Listen on the given address without any authentication mechanism.
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        // Register "service_" as the instance through which we'll communicate with
        // clients. In this case it corresponds to an *asynchronous* service.
        builder.RegisterService(&service_);
        // Get hold of the completion queue used for the asynchronous communication
        // with the gRPC runtime.
        for (int i = 0; i < configData.thread_pool; ++i) {
            cq_.push_back( builder.AddCompletionQueue());
        }

        // Finally assemble the server.
        server_ = builder.BuildAndStart();
        std::cout << "Server listening on " << server_address << std::endl;

        // Proceed to the server's main loop.
        std::thread th[configData.thread_pool];
        int arr[100];
        for (int i = 0; i < configData.thread_pool; ++i) {
            arr[i]=i;
            if(configData.cache_replacement=="LRU")
                th[i]=std::thread(&ServerImpl::HandleRpcsLRU, this,arr[i]);
            else
                th[i]=std::thread(&ServerImpl::HandleRpcsLFU, this,arr[i]);
        }
        for (int i = 0; i < configData.thread_pool; ++i) {
            th[i].join();
        }
    }
private:
    // Class encompasing the state and logic needed to serve a request.
    class CallDataLRU {
    public:
        CallDataLRU(KV::AsyncService * service, ServerCompletionQueue * cq, int type)
        : service_(service), responder_(&ctx_), cq_(cq), status_(CREATE)
        {
            type_of_request = type;
            // Invoke the serving logic right away.
            Proceed();
        }
        void Proceed() {
            if (status_ == CREATE) {
                // Make this instance progress to the PROCESS state.
                status_ = PROCESS;
                // As part of the initial CREATE state, we *request* that the system
                // start processing SayHello requests. In this request, "this" acts are
                // the tag uniquely identifying the request (so that different CallData
                // instances can serve different requests concurrently), in this case
                // the memory address of this CallData instance.
                if(type_of_request==0){
                    service_->RequestGET(&ctx_,&request_get,&responder_,cq_,cq_,this);
                }else if(type_of_request==1){
                    service_->RequestPUT(&ctx_,&request_put,&responder_,cq_,cq_,this);
                }else if(type_of_request==2){
                    service_->RequestDEL(&ctx_,&request_del,&responder_,cq_,cq_,this);
                }

            }
            else if (status_ == PROCESS) {


                int time=3;
                while (time--)
                {
                    std::cout<<"i m sleep"<<time<<std::endl;
                    sleep(1);
                }
                //business logic
                if(request_get.key()!="")
                {
                    new CallDataLRU(service_, cq_, 0);
                    // i m get service...
                    std::cout<<"get"<<std::endl;

                }else if(request_put.key()!="")
                {
                    new CallDataLRU(service_, cq_, 1);
                    // i m put service...
                    std::cout<<"put"<<std::endl;
                }
                else
                {
                    new CallDataLRU(service_, cq_, 2);


                    std::cout<<"del"<<std::endl;

                }
//                std::cout<<"1. "<<request_put.key()<<" 2. "<<request_get.key()<<"\n";


                // The actual processing.
                std::string prefix("Hello ");
                reply_.set_key(prefix );

                status_ = FINISH;

                responder_.Finish(reply_, Status::OK, this);
            }
            else {
                GPR_ASSERT(status_ == FINISH);
                std::cout<<"I m in delete\n";
                // Once in the FINISH state, deallocate ourselves (CallData).
                delete this;
            }
        }

    private:
        // The means of communication with the gRPC runtime for an asynchronous
        // server.
        int type_of_request;
        KV::AsyncService* service_;
        // The producer-consumer queue where for asynchronous server notifications.
        ServerCompletionQueue* cq_;
        // Context for the rpc, allowing to tweak aspects of it such as the use
        // of compression, authentication, as well as to send metadata back to the
        // client.
        ServerContext ctx_;

        // What we get from the client.
        GetKeyRequest request_get;
        PutKeyRequest request_put;
        DelKeyRequest request_del;
        // What we send back to the client.
        keyvaluepackage::Reply reply_;

        // The means to get back to the client.
        ServerAsyncResponseWriter<keyvaluepackage::Reply> responder_;
        // Let's implement a tiny state machine with the following states.
        enum CallStatus { CREATE, PROCESS, FINISH };
        CallStatus status_;  // The current serving state.
    };

    // This can be run in multiple threads if needed.
    void HandleRpcsLRU(int idx) {
        // Spawn a new CallData instance to serve new clients.

        new CallDataLRU(&service_, cq_[idx].get(), 0);
        new CallDataLRU(&service_, cq_[idx].get(), 1);
        new CallDataLRU(&service_, cq_[idx].get(), 2);
        void* tag;  // uniquely identifies a request.
        bool ok;
        while (true) {
            // Block waiting to read the next event from the completion queue. The
            // event is uniquely identified by its tag, which in this case is the
            // memory address of a CallData instance.
            // The return value of Next should always be checked. This return value
            // tells us whether there is any kind of event or cq_ is shutting down.
            GPR_ASSERT(cq_[idx]->Next(&tag, &ok));
            GPR_ASSERT(ok);
            static_cast<CallDataLRU*>(tag)->Proceed();
        }
    }

    class CallDataLFU {
    public:
        CallDataLFU(KV::AsyncService * service, ServerCompletionQueue * cq, int type)
        : service_(service), responder_(&ctx_), cq_(cq), status_(CREATE)
        {
            type_of_request = type;
            // Invoke the serving logic right away.
            Proceed();

        }
        void Proceed() {
            if (status_ == CREATE) {
                // Make this instance progress to the PROCESS state.
                status_ = PROCESS;
                // As part of the initial CREATE state, we *request* that the system
                // start processing SayHello requests. In this request, "this" acts are
                // the tag uniquely identifying the request (so that different CallData
                // instances can serve different requests concurrently), in this case
                // the memory address of this CallData instance.
                if(type_of_request==0){
                    service_->RequestGET(&ctx_,&request_get,&responder_,cq_,cq_,this);
                }else if(type_of_request==1){
                    service_->RequestPUT(&ctx_,&request_put,&responder_,cq_,cq_,this);
                }else if(type_of_request==2){
                    service_->RequestDEL(&ctx_,&request_del,&responder_,cq_,cq_,this);
                }

            }
            else if (status_ == PROCESS) {

                //business logic
                // The actual processing.
                std::string prefix("Hello ");
                reply_.set_key(prefix );

                if(request_get.key()!="")
                {
                    new CallDataLFU(service_, cq_, 0);
                    // try to find in cache
                    auto it = keyFeqValue.find(request_get.key());
                    //Present into cache
                    if(it!=keyFeqValue.end())
                    {
                        //lock require
                        std::unique_lock<std::mutex> lock (door);
                        std::pair<int,std::string> value=keyFeqValue[request_get.key()];
                        auto it1=feqKeq.find({value.first,request_get.key()});
                        feqKeq.erase(it1);
                        keyFeqValue[request_get.key()]={value.first+1,request_get.key()};
                        feqKeq.insert({value.first+1,request_get.key()});
                        reply_.set_value(value.second );
                        reply_.set_key(request_get.key());
                    } else
                    {//don't present into cache
                        //lock don't

//                       erase if cache size increase
                        if(feqKeq.size()>NUM_OF_RECORD)
                        {
                            auto it=feqKeq.begin();
                            keyFeqValue.erase(*it->second);
                            feqKeq.erase(it);
                        }
                    }

                }
                else if(request_put.key()!="")
                {
                    new CallDataLFU(service_, cq_, 1);
                    // i m put service...
                    auto it = keyFeqValue.find(request_put.key());
                    //Present into cache
                    if(it!=keyFeqValue.end())
                    {
                        std::unique_lock<std::mutex> lock (door);
                        std::pair<int,std::string> value=keyFeqValue[request_put.key()];
                        auto it1=feqKeq.find({value.first,request_put.key()});
                        feqKeq.erase(it1);
                        keyFeqValue[request_put.key()]={value.first+1,request_put.key()};
                        feqKeq.insert({value.first+1,request_put.key()});
                        reply_.set_value("Success");
                        reply_.set_key(request_put.key());
                    } else{
                        std::unique_lock<std::mutex> lock (door);
                        keyFeqValue[request_put.key()]={1,request_put.value()};
                        feqKeq.insert({1,request_put.key()});
                        if(feqKeq.size()>NUM_OF_RECORD)
                        {
                            auto it=feqKeq.begin();
                            keyFeqValue.erase(*it->second);
                            feqKeq.erase(it);
                        }
                    }
                    //logic of file update

                    std::cout<<"put"<<std::endl;
                }
                else if(request_del.key()!="")
                {
                    new CallDataLFU(service_, cq_, 2);
                    auto it = keyFeqValue.find(request_del.key());
                    //Present into cache
                    if(it!=keyFeqValue.end())
                    {
                        //lock require
                        std::unique_lock<std::mutex> lock (door);
                        std::pair<int,std::string> value=keyFeqValue[request_del.key()];
                        keyFeqValue.erase(request_del.key());
                        auto it1=feqKeq.find({value.first,request_del.key()});
                        feqKeq.erase(it1);
                    }
                    //delete from file


                    std::cout<<"del"<<std::endl;

                }


                status_ = FINISH;

                responder_.Finish(reply_, Status::OK, this);
            }
            else {
                GPR_ASSERT(status_ == FINISH);
                std::cout<<"I m in delete\n";
                // Once in the FINISH state, deallocate ourselves (CallData).
                delete this;
            }
        }

    private:
        // The means of communication with the gRPC runtime for an asynchronous
        // server.
        int type_of_request;
        KV::AsyncService* service_;
        // The producer-consumer queue where for asynchronous server notifications.
        ServerCompletionQueue* cq_;
        // Context for the rpc, allowing to tweak aspects of it such as the use
        // of compression, authentication, as well as to send metadata back to the
        // client.
        ServerContext ctx_;

        // What we get from the client.
        GetKeyRequest request_get;
        PutKeyRequest request_put;
        DelKeyRequest request_del;
        // What we send back to the client.
        keyvaluepackage::Reply reply_;

        // The means to get back to the client.
        ServerAsyncResponseWriter<keyvaluepackage::Reply> responder_;
        // Let's implement a tiny state machine with the following states.
        enum CallStatus { CREATE, PROCESS, FINISH };
        CallStatus status_;  // The current serving state.
    };

    // This can be run in multiple threads if needed.
    void HandleRpcsLFU(int idx) {
        // Spawn a new CallData instance to serve new clients.

        new CallDataLFU(&service_, cq_[idx].get(), 0);
        new CallDataLFU(&service_, cq_[idx].get(), 1);
        new CallDataLFU(&service_, cq_[idx].get(), 2);
        void* tag;  // uniquely identifies a request.
        bool ok;
        while (true) {
            // Block waiting to read the next event from the completion queue. The
            // event is uniquely identified by its tag, which in this case is the
            // memory address of a CallData instance.
            // The return value of Next should always be checked. This return value
            // tells us whether there is any kind of event or cq_ is shutting down.
            GPR_ASSERT(cq_[idx]->Next(&tag, &ok));
            GPR_ASSERT(ok);
            static_cast<CallDataLFU*>(tag)->Proceed();
        }
    }
    std::vector<std::unique_ptr<ServerCompletionQueue>> cq_;
    KV::AsyncService service_;
    std::unique_ptr<Server> server_;
};
;
int main(int argc, char** argv) {
    //struct configData contain data of config file
    struct conf configData = print();
    ServerImpl server;
    server.Run(configData);

    return 0;
}