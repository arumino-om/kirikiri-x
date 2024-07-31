#pragma once
#include "../native_instances/layer_instance.h"

namespace LibRuntime::NativeClasses {
    class LayerNativeClass : public tTJSNativeClass {
    public:
        LayerNativeClass();

        static tjs_uint32 ClassID;
        tTJSNativeInstance *CreateNativeInstance() override;
    };
}
