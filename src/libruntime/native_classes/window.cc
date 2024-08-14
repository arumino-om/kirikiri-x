#include "window.h"
#include "../native_instances/window_instance.h"

using namespace LibRuntime::NativeClasses;

tjs_uint32 WindowNativeClass::ClassID = -1;

WindowNativeClass::WindowNativeClass() : tTJSNativeClass(TJS_W("Window")) {
    TJS_BEGIN_NATIVE_MEMBERS(Window)
    {
        TJS_DECL_EMPTY_FINALIZE_METHOD

        TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL(/*this name*/_this, /*type*/NativeInstances::WindowNativeInstance, /*TJS class name*/Window)
        {
            return TJS_S_OK;
        }
        TJS_END_NATIVE_CONSTRUCTOR_DECL(Window)


        TJS_BEGIN_NATIVE_METHOD_DECL(add) {
            TJS_GET_NATIVE_INSTANCE(_this, NativeInstances::WindowNativeInstance)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            auto clo = param[0]->AsObjectClosureNoAddRef();
            _this->add_object(clo);
            return TJS_S_OK;
        }
        TJS_END_NATIVE_METHOD_DECL(add)
    }
    TJS_END_NATIVE_MEMBERS
}

tTJSNativeInstance *WindowNativeClass::CreateNativeInstance() {
    return new NativeInstances::WindowNativeInstance();
}