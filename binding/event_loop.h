#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H

#include <unistd.h>
#include <stdio.h>
#include "node.h"
#include "uv.h"
#include "napi.h"

void Start(const Napi::CallbackInfo &args);
Napi::Object Initialize(Napi::Env env, Napi::Object exports);

#endif