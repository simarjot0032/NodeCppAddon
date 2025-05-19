#pragma once

#include <napi.h>


class Hello : public Napi::ObjectWrap<Hello> {
public:
    Hello(const Napi::CallbackInfo &);
    Napi::Value Add(const Napi::CallbackInfo &);    
    static Napi::Function GetClass( Napi::Env);
};