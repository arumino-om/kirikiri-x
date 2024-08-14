#include "layer.h"
#include "../native_instances/layer_instance.h"

using namespace LibRuntime::NativeClasses;

tjs_uint32 LayerNativeClass::ClassID = -1;

LayerNativeClass::LayerNativeClass() : tTJSNativeClass(TJS_W("Layer")) {
    TJS_BEGIN_NATIVE_MEMBERS(LayerNativeClass)
    {
        TJS_DECL_EMPTY_FINALIZE_METHOD

        TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL(_this, NativeInstances::LayerNativeInstance, Layer)
        {
            return TJS_S_OK;
        }
        TJS_END_NATIVE_CONSTRUCTOR_DECL(Layer)

        TJS_BEGIN_NATIVE_METHOD_DECL(add) {
            return TJS_S_OK;
        }
        TJS_END_NATIVE_METHOD_DECL(add)
    }
    TJS_END_NATIVE_MEMBERS
}

tTJSNativeInstance *LayerNativeClass::CreateNativeInstance() {
    return new NativeInstances::LayerNativeInstance();
}