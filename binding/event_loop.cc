#include "event_loop.h"

void on_close(uv_handle_t *handle)
{
    delete handle;
}

void cleanup(void* data)
{
    uv_close((uv_handle_t *)data, on_close);
}

void Start(const Napi::CallbackInfo &args)
{
    Napi::Env env = args.Env();
    uv_loop_t *loop;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    napi_get_uv_event_loop(env, &loop);
    uv_prepare_t* prepare_handle = new uv_prepare_t;
    uv_prepare_init(loop, prepare_handle);
    uv_unref((uv_handle_t *)prepare_handle);
    uv_prepare_start(prepare_handle, [](uv_prepare_t *handle) {});
    node::AddEnvironmentCleanupHook(isolate, cleanup, prepare_handle);
}

Napi::Object Initialize(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "start"), Napi::Function::New(env, Start));
    return exports;
};

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Initialize)