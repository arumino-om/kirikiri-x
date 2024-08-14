#pragma once
#include <tjs.h>
#include <tjsNative.h>

namespace LibRuntime::NativeClasses {
    class LayerNativeClass : public tTJSNativeClass {
    public:
        LayerNativeClass();

        static tjs_uint32 ClassID;
        tTJSNativeInstance *CreateNativeInstance() override;
    };
}
