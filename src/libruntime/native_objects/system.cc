#include "system.h"
#include "minimal.h"
#include "../event_manager.h"

using namespace LibRuntime::NativeObjects;

tjs_uint32 SystemNativeClass::ClassID = -1;

SystemNativeClass::SystemNativeClass() : tTJSNativeClass(TJS_W("System")) {
    TJS_BEGIN_NATIVE_MEMBERS(System)
        TJS_DECL_EMPTY_FINALIZE_METHOD

        //===== CONSTRUCTOR =====
        TJS_BEGIN_NATIVE_CONSTRUCTOR_DECL_NO_INSTANCE(System)
            return TJS_S_OK;
        TJS_END_NATIVE_CONSTRUCTOR_DECL(System)


        //===== METHODS =====
        TJS_BEGIN_NATIVE_METHOD_DECL(addContinuousHandler)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            auto clo = param[0]->AsObjectClosureNoAddRef();
            EventManager::add_continuous_handler(clo);
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(addContinuousHandler)


        TJS_BEGIN_NATIVE_METHOD_DECL(assignMessage)
            if (numparams < 2) return TJS_E_BADPARAMCOUNT;
            ScriptManager::assign_message(param[0]->GetString(), param[1]->GetString());
        TJS_END_NATIVE_METHOD_DECL(assignMessage)


        TJS_BEGIN_NATIVE_METHOD_DECL(createAppLock)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            auto func_result=  KrkrRuntime::sysfunc->create_app_lock(param[0]->GetString());
            if (result != nullptr) *result = func_result;
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(createAppLock)


        TJS_BEGIN_NATIVE_METHOD_DECL(getArgument)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            tjs_string argval;

            if (!KrkrRuntime::get_argument(param[0]->GetString(), argval)) {
                result->Clear();
                return TJS_S_OK;
            }

            if (result != nullptr) *result = argval.c_str();
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(getArgument)


        TJS_BEGIN_NATIVE_METHOD_DECL(exit)
            exit(param[0]->AsInteger());
            return TJS_S_OK;    //関数が戻ることはないはず
        TJS_END_NATIVE_METHOD_DECL(exit)


        TJS_BEGIN_NATIVE_METHOD_DECL(setArgument)
            if (numparams < 2) return TJS_E_BADPARAMCOUNT;
            KrkrRuntime::set_argument(param[0]->GetString(), param[1]->GetString());
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(setArgument)


        TJS_BEGIN_NATIVE_METHOD_DECL(shellExecute)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            const tjs_char *program = param[0]->GetString();
            const tjs_char *args = numparams > 1 ? param[1]->GetString() : nullptr;
            KrkrRuntime::sysfunc->execute(program, args);
        TJS_END_NATIVE_METHOD_DECL(shellExecute)


        TJS_BEGIN_NATIVE_METHOD_DECL(terminate)
                KrkrRuntime::request_quit(param[0]->AsInteger());
                return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(terminate)
    TJS_END_NATIVE_MEMBERS
}

tTJSNativeInstance *SystemNativeClass::CreateNativeInstance() {
    return nullptr;
}