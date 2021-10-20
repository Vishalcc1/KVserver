#include <fstream>
#include "unistd.h"
#include <iostream>
#include <memory>
#include <string>

#include <grpc/support/log.h>
#include <grpcpp/grpcpp.h>
#include <thread>

#include "keyvaluepackage.grpc.pb.h"
#include "helper.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;
using keyvaluepackage::KV;
using keyvaluepackage::GetKeyRequest;
using keyvaluepackage::Reply;
using keyvaluepackage::PutKeyRequest;
using keyvaluepackage::DelKeyRequest;

class GreeterClient {
public:
    explicit GreeterClient(std::shared_ptr <Channel> channel)
            : stub_(KV::NewStub(channel)) {}
    void GET(const std::string& k)
    {
        std::cout<<"I m here"<<std::endl;
        GetKeyRequest request;
        request.set_key(k);

        AsyncClientCall* call = new AsyncClientCall;

        call->response_reader = stub_->PrepareAsyncGET(&call->context,request,&cq_);
        call->response_reader->StartCall();
        call->response_reader->Finish(&call->reply,&call->status,(void *)call);

        return;
    }
    void PUT(const std::string& k,const std::string& k2)
    {
        PutKeyRequest request;
        request.set_key(k);
        request.set_value(k2);
        AsyncClientCall* call = new AsyncClientCall;

        call->response_reader = stub_->PrepareAsyncPUT(&call->context,request,&cq_);
        call->response_reader->StartCall();
        call->response_reader->Finish(&call->reply,&call->status,(void *)call);


    }
    void DEL(const std::string& k)
    {
        DelKeyRequest request;
        request.set_key(k);

        AsyncClientCall* call = new AsyncClientCall;

        call->response_reader = stub_->PrepareAsyncDEL(&call->context,request,&cq_);
        call->response_reader->StartCall();
        call->response_reader->Finish(&call->reply,&call->status,(void *)call);


    }
    void AsyncCompleteRpc() {
        void* got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        while (cq_.Next(&got_tag, &ok)) {
            // The tag in this example is the memory location of the call object
            AsyncClientCall* call = static_cast<AsyncClientCall*>(got_tag);

            // Verify that the request was completed successfully. Note that "ok"
            // corresponds solely to the request for updates introduced by Finish().
            GPR_ASSERT(ok);

            if (call->status.ok())
                std::cout<<call->reply.key()<<std::endl;
            else
                std::cout << "RPC failed" << std::endl;

            // Once we're complete, deallocate the call object.
            delete call;
        }
    }
private:
    // struct for keeping state and data information
    struct AsyncClientCall {
        // Container for the data we expect from the server.
        keyvaluepackage::Reply reply;

        // Context for the client. It could be used to convey extra information to
        // the server and/or tweak certain RPC behaviors.
        ClientContext context;

        // Storage for the status of the RPC upon completion.
        Status status;

        std::unique_ptr<ClientAsyncResponseReader<keyvaluepackage::Reply>> response_reader;
    };


    // Out of the passed in Channel comes the stub, stored here, our view of the
    // server's exposed services.
    std::unique_ptr<KV::Stub> stub_;

    // The producer-consumer queue we use to communicate asynchronously with the
    // gRPC runtime.
    CompletionQueue cq_;
};
int main(int argc, char** argv) {

    struct conf configData= print();

    GreeterClient greeter(grpc::CreateChannel(
            "localhost:"+ std::to_string(configData.port), grpc::InsecureChannelCredentials()));
    std::thread thread = std::thread(&GreeterClient::AsyncCompleteRpc, &greeter);
    std::string s1,s2,user;
    while (true)
    {
        std::cout<<"1 For get"<<std::endl;
        std::cout<<"2 For put"<<std::endl;
        std::cout<<"3 For del"<<std::endl;
        int a;

        std::cin>>a;
        if(a==1)
        {
            user="world " + std::to_string(10);
            std::cout<<user<<std::endl;
            greeter.GET(user);
        } else if(a==2)
        {
            std::cin>>s1>>s2;
            std::cout<<user<<std::endl;
            greeter.PUT(s1,s2);
        } else if(a==3)
        {
            std::cin>>s1;
            greeter.DEL(s1);
        } else
        {
            std::cout<<"Please give a valid input"<<std::endl;
        }
    }
    thread.join();
    return 0;
}
