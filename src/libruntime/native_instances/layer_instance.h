#pragma once
#include <tjs.h>
#include <tjsError.h>
#include <tjsNative.h>

namespace LibRuntime::NativeInstances {
    class LayerNativeInstance : public tTJSNativeInstance {
    public:
        LayerNativeInstance();
        tjs_error TJS_INTF_METHOD Construct(tjs_int numparams, tTJSVariant **param, iTJSDispatch2 *tjs_obj);
        void TJS_INTF_METHOD Invalidate();
    };
}
