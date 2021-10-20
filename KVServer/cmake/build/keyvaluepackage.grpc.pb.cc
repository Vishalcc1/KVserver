// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: keyvaluepackage.proto

#include "keyvaluepackage.pb.h"
#include "keyvaluepackage.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace keyvaluepackage {

static const char* KV_method_names[] = {
  "/keyvaluepackage.KV/GET",
  "/keyvaluepackage.KV/PUT",
  "/keyvaluepackage.KV/DEL",
};

std::unique_ptr< KV::Stub> KV::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< KV::Stub> stub(new KV::Stub(channel, options));
  return stub;
}

KV::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GET_(KV_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_PUT_(KV_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DEL_(KV_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status KV::Stub::GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::keyvaluepackage::Reply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GET_, context, request, response);
}

void KV::Stub::async::GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GET_, context, request, response, std::move(f));
}

void KV::Stub::async::GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GET_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* KV::Stub::PrepareAsyncGETRaw(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::keyvaluepackage::Reply, ::keyvaluepackage::GetKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GET_, context, request);
}

::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* KV::Stub::AsyncGETRaw(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGETRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status KV::Stub::PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::keyvaluepackage::Reply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_PUT_, context, request, response);
}

void KV::Stub::async::PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PUT_, context, request, response, std::move(f));
}

void KV::Stub::async::PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_PUT_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* KV::Stub::PrepareAsyncPUTRaw(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::keyvaluepackage::Reply, ::keyvaluepackage::PutKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_PUT_, context, request);
}

::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* KV::Stub::AsyncPUTRaw(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncPUTRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status KV::Stub::DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::keyvaluepackage::Reply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DEL_, context, request, response);
}

void KV::Stub::async::DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DEL_, context, request, response, std::move(f));
}

void KV::Stub::async::DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DEL_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* KV::Stub::PrepareAsyncDELRaw(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::keyvaluepackage::Reply, ::keyvaluepackage::DelKeyRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DEL_, context, request);
}

::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* KV::Stub::AsyncDELRaw(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDELRaw(context, request, cq);
  result->StartCall();
  return result;
}

KV::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      KV_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< KV::Service, ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](KV::Service* service,
             ::grpc::ServerContext* ctx,
             const ::keyvaluepackage::GetKeyRequest* req,
             ::keyvaluepackage::Reply* resp) {
               return service->GET(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      KV_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< KV::Service, ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](KV::Service* service,
             ::grpc::ServerContext* ctx,
             const ::keyvaluepackage::PutKeyRequest* req,
             ::keyvaluepackage::Reply* resp) {
               return service->PUT(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      KV_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< KV::Service, ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](KV::Service* service,
             ::grpc::ServerContext* ctx,
             const ::keyvaluepackage::DelKeyRequest* req,
             ::keyvaluepackage::Reply* resp) {
               return service->DEL(ctx, req, resp);
             }, this)));
}

KV::Service::~Service() {
}

::grpc::Status KV::Service::GET(::grpc::ServerContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status KV::Service::PUT(::grpc::ServerContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status KV::Service::DEL(::grpc::ServerContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace keyvaluepackage
