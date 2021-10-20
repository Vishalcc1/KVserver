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

#include "keyvaluepackage.grpc.pb.h"
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

class ServerImpl final {
public:
    ~ServerImpl() {
        server_->Shutdown();
        // Always shutdown the completion queue after the server.
        cq_[0]->Shutdown();
    }
    void Run(struct conf configData) {

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
            th[i]=std::thread(&ServerImpl::HandleRpcs1, this,arr[i]);
        }
        for (int i = 0; i < configData.thread_pool; ++i) {
            th[i].join();
        }
//        HandleRpcs1();
    }
private:
    // Class encompasing the state and logic needed to serve a request.
    class CallData {
    public:
        CallData(KV::AsyncService * service, ServerCompletionQueue * cq, int type)
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
                    new CallData(service_, cq_, 0);
                    // i m get service...
                    std::cout<<"get"<<std::endl;

                }else if(request_put.key()!="")
                {
                    new CallData(service_, cq_, 1);
                    // i m put service...
                    std::cout<<"put"<<std::endl;
                }
                else
                {
                    new CallData(service_, cq_, 2);
                    // i m del service... n^2
//                           a
//                        b   d
//                        c       c

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
    void HandleRpcs1(int idx) {
        // Spawn a new CallData instance to serve new clients.

        new CallData(&service_, cq_[idx].get(), 0);
        new CallData(&service_, cq_[idx].get(), 1);
        new CallData(&service_, cq_[idx].get(), 2);
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
            static_cast<CallData*>(tag)->Proceed();
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