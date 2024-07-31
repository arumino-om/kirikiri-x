#include "layer_instance.h"

using namespace LibRuntime::NativeInstances;

LayerNativeInstance::LayerNativeInstance() {

}

tjs_error LayerNativeInstance::Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj) {
    if (numparams < 2) return TJS_E_BADPARAMCOUNT;
    auto clo = param[0]->AsObjectClosureNoAddRef();
    if (clo.Object == nullptr) return TJS_E_INVALIDPARAM;

    auto clo2 = param[1]->AsObjectClosureNoAddRef();
    if (clo2.Object == nullptr) {
        return TJS_S_OK;
    }

    return TJS_S_OK;
}

void LayerNativeInstance::Invalidate() {
    tTJSNativeInstance::Invalidate();
}
