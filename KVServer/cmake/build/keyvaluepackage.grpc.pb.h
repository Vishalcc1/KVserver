// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: keyvaluepackage.proto
// Original file comments:
// Copyright 2015 gRPC authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef GRPC_keyvaluepackage_2eproto__INCLUDED
#define GRPC_keyvaluepackage_2eproto__INCLUDED

#include "keyvaluepackage.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace keyvaluepackage {

// The greeting service definition.
class KV final {
 public:
  static constexpr char const* service_full_name() {
    return "keyvaluepackage.KV";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Sends a greeting
    virtual ::grpc::Status GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::keyvaluepackage::Reply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>> AsyncGET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>>(AsyncGETRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>> PrepareAsyncGET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>>(PrepareAsyncGETRaw(context, request, cq));
    }
    virtual ::grpc::Status PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::keyvaluepackage::Reply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>> AsyncPUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>>(AsyncPUTRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>> PrepareAsyncPUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>>(PrepareAsyncPUTRaw(context, request, cq));
    }
    virtual ::grpc::Status DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::keyvaluepackage::Reply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>> AsyncDEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>>(AsyncDELRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>> PrepareAsyncDEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>>(PrepareAsyncDELRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Sends a greeting
      virtual void GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>* AsyncGETRaw(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>* PrepareAsyncGETRaw(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>* AsyncPUTRaw(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>* PrepareAsyncPUTRaw(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>* AsyncDELRaw(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::keyvaluepackage::Reply>* PrepareAsyncDELRaw(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::keyvaluepackage::Reply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>> AsyncGET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>>(AsyncGETRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>> PrepareAsyncGET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>>(PrepareAsyncGETRaw(context, request, cq));
    }
    ::grpc::Status PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::keyvaluepackage::Reply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>> AsyncPUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>>(AsyncPUTRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>> PrepareAsyncPUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>>(PrepareAsyncPUTRaw(context, request, cq));
    }
    ::grpc::Status DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::keyvaluepackage::Reply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>> AsyncDEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>>(AsyncDELRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>> PrepareAsyncDEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>>(PrepareAsyncDELRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)>) override;
      void GET(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) override;
      void PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)>) override;
      void PUT(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) override;
      void DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response, std::function<void(::grpc::Status)>) override;
      void DEL(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* AsyncGETRaw(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* PrepareAsyncGETRaw(::grpc::ClientContext* context, const ::keyvaluepackage::GetKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* AsyncPUTRaw(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* PrepareAsyncPUTRaw(::grpc::ClientContext* context, const ::keyvaluepackage::PutKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* AsyncDELRaw(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::keyvaluepackage::Reply>* PrepareAsyncDELRaw(::grpc::ClientContext* context, const ::keyvaluepackage::DelKeyRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GET_;
    const ::grpc::internal::RpcMethod rpcmethod_PUT_;
    const ::grpc::internal::RpcMethod rpcmethod_DEL_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Sends a greeting
    virtual ::grpc::Status GET(::grpc::ServerContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response);
    virtual ::grpc::Status PUT(::grpc::ServerContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response);
    virtual ::grpc::Status DEL(::grpc::ServerContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_GET : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GET() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GET() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GET(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGET(::grpc::ServerContext* context, ::keyvaluepackage::GetKeyRequest* request, ::grpc::ServerAsyncResponseWriter< ::keyvaluepackage::Reply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_PUT : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_PUT() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_PUT() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PUT(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestPUT(::grpc::ServerContext* context, ::keyvaluepackage::PutKeyRequest* request, ::grpc::ServerAsyncResponseWriter< ::keyvaluepackage::Reply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_DEL : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_DEL() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_DEL() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DEL(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDEL(::grpc::ServerContext* context, ::keyvaluepackage::DelKeyRequest* request, ::grpc::ServerAsyncResponseWriter< ::keyvaluepackage::Reply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GET<WithAsyncMethod_PUT<WithAsyncMethod_DEL<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GET : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GET() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::keyvaluepackage::GetKeyRequest* request, ::keyvaluepackage::Reply* response) { return this->GET(context, request, response); }));}
    void SetMessageAllocatorFor_GET(
        ::grpc::MessageAllocator< ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GET() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GET(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GET(
      ::grpc::CallbackServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_PUT : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_PUT() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::keyvaluepackage::PutKeyRequest* request, ::keyvaluepackage::Reply* response) { return this->PUT(context, request, response); }));}
    void SetMessageAllocatorFor_PUT(
        ::grpc::MessageAllocator< ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_PUT() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PUT(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* PUT(
      ::grpc::CallbackServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_DEL : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_DEL() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::keyvaluepackage::DelKeyRequest* request, ::keyvaluepackage::Reply* response) { return this->DEL(context, request, response); }));}
    void SetMessageAllocatorFor_DEL(
        ::grpc::MessageAllocator< ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(2);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_DEL() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DEL(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* DEL(
      ::grpc::CallbackServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_GET<WithCallbackMethod_PUT<WithCallbackMethod_DEL<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GET : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GET() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GET() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GET(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_PUT : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_PUT() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_PUT() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PUT(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_DEL : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_DEL() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_DEL() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DEL(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GET : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GET() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GET() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GET(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGET(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_PUT : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_PUT() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_PUT() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PUT(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestPUT(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_DEL : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_DEL() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_DEL() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DEL(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDEL(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GET : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GET() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GET(context, request, response); }));
    }
    ~WithRawCallbackMethod_GET() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GET(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GET(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_PUT : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_PUT() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->PUT(context, request, response); }));
    }
    ~WithRawCallbackMethod_PUT() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status PUT(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* PUT(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_DEL : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_DEL() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->DEL(context, request, response); }));
    }
    ~WithRawCallbackMethod_DEL() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status DEL(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* DEL(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GET : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GET() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::keyvaluepackage::GetKeyRequest, ::keyvaluepackage::Reply>* streamer) {
                       return this->StreamedGET(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GET() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GET(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::GetKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGET(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::keyvaluepackage::GetKeyRequest,::keyvaluepackage::Reply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_PUT : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_PUT() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::keyvaluepackage::PutKeyRequest, ::keyvaluepackage::Reply>* streamer) {
                       return this->StreamedPUT(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_PUT() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status PUT(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::PutKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedPUT(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::keyvaluepackage::PutKeyRequest,::keyvaluepackage::Reply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_DEL : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_DEL() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler<
          ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::keyvaluepackage::DelKeyRequest, ::keyvaluepackage::Reply>* streamer) {
                       return this->StreamedDEL(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_DEL() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status DEL(::grpc::ServerContext* /*context*/, const ::keyvaluepackage::DelKeyRequest* /*request*/, ::keyvaluepackage::Reply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedDEL(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::keyvaluepackage::DelKeyRequest,::keyvaluepackage::Reply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GET<WithStreamedUnaryMethod_PUT<WithStreamedUnaryMethod_DEL<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_GET<WithStreamedUnaryMethod_PUT<WithStreamedUnaryMethod_DEL<Service > > > StreamedService;
};

}  // namespace keyvaluepackage


#endif  // GRPC_keyvaluepackage_2eproto__INCLUDED