#include "Hello.h"
#include <napi.h>
using namespace Napi;

Napi::Function Hello::GetClass(Napi::Env env) {
    return DefineClass(env, "Hello", {
        Hello::InstanceMethod("Add", &Hello::Add)
    });
}



Hello::Hello(const CallbackInfo &info) : ObjectWrap<Hello>(info) {
    Napi::Env env=info.Env();
   
};
Napi::Value Hello::Add(const CallbackInfo &info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Two numbers expected").ThrowAsJavaScriptException();
        return env.Null();
    }

    double arg0 = info[0].As<Napi::Number>().DoubleValue();
    double arg1 = info[1].As<Napi::Number>().DoubleValue();

    double sum = arg0 + arg1;

    return Napi::Number::New(env, sum);
};
#include <napi.h>
#include "Hello.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    exports.Set("Hello", Hello::GetClass(env));
    return exports;
}
NODE_API_MODULE(addon, InitAll)
