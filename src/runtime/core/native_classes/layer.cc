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

        TJS_BEGIN_NATIVE_METHOD_DECL(setPos) {
            if (numparams < 2) return TJS_E_BADPARAMCOUNT;

            TJS_GET_NATIVE_INSTANCE(_this, NativeInstances::LayerNativeInstance)
            if (param[0]->Type() != tvtInteger || param[1]->Type() != tvtInteger) return TJS_E_INVALIDPARAM;
            _this->set_position(param[0]->AsInteger(), param[1]->AsInteger());

            if (numparams >= 4) {
                if (param[2]->Type() != tvtInteger || param[3]->Type() != tvtInteger) return TJS_E_INVALIDPARAM;
                _this->set_size(param[2]->AsInteger(), param[3]->AsInteger());
            }

            return TJS_S_OK;
        }
        TJS_END_NATIVE_METHOD_DECL(setPos)
    }
    TJS_END_NATIVE_MEMBERS
}

tTJSNativeInstance *LayerNativeClass::CreateNativeInstance() {
    return new NativeInstances::LayerNativeInstance();
}