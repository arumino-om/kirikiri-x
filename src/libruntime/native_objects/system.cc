#include "system.h"
#include "minimal.h"

using namespace LibRuntime::NativeObjects;

tjs_uint32 SystemNativeClass::ClassID = -1;

SystemNativeClass::SystemNativeClass() : tTJSNativeClass(TJS_W("System")) {
    TJS_BEGIN_NATIVE_MEMBERS(System)
        TJS_DECL_EMPTY_FINALIZE_METHOD
        // constructor
        TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL_NO_INSTANCE(System)
                return TJS_S_OK;
        TJS_END_NATIVE_CONSTRUCTOR_DECL(System)

        // methods
        TJS_BEGIN_NATIVE_METHOD_DECL(exit)
            exit(param[0]->AsInteger());
            return TJS_S_OK;    //関数が戻ることはないはず
        TJS_END_NATIVE_METHOD_DECL(exit)

        TJS_BEGIN_NATIVE_METHOD_DECL(terminate)
            KrkrRuntime::request_exit(param[0]->AsInteger());
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(terminate)

        TJS_BEGIN_NATIVE_METHOD_DECL(getArgument)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            tjs_string argval;
            if (!KrkrRuntime::get_argument(param[0]->GetString(), argval)) {
                result = new tTJSVariant();
            }
            result = new tTJSVariant(argval);
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(getArgument)
    TJS_END_NATIVE_MEMBERS
}

tTJSNativeInstance *SystemNativeClass::CreateNativeInstance() {
    return nullptr;
}