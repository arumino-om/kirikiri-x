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
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(assignMessage)


        TJS_BEGIN_NATIVE_METHOD_DECL(createAppLock)
            if (numparams < 1) return TJS_E_BADPARAMCOUNT;
            auto func_result=  KrkrRuntime::sysfunc->create_app_lock(param[0]->GetString());
            if (result != nullptr) *result = func_result;
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(createAppLock)


        TJS_BEGIN_NATIVE_METHOD_DECL(createUUID)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(createUUID)


        TJS_BEGIN_NATIVE_METHOD_DECL(doCompact)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(doCompact)


        TJS_BEGIN_NATIVE_METHOD_DECL(dumpHeap)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(dumpHeap)


        TJS_BEGIN_NATIVE_METHOD_DECL(exit)
                exit(param[0]->AsInteger());
                return TJS_S_OK;    //関数が戻ることはないはず
        TJS_END_NATIVE_METHOD_DECL(exit)


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


        TJS_BEGIN_NATIVE_METHOD_DECL(getKeyState)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(getKeyState)


        TJS_BEGIN_NATIVE_METHOD_DECL(getTickCount)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(getTickCount)


        TJS_BEGIN_NATIVE_METHOD_DECL(inform)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(inform)


        TJS_BEGIN_NATIVE_METHOD_DECL(readRegValue)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(readRegValue)


        TJS_BEGIN_NATIVE_METHOD_DECL(removeContinuousHandler)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(removeContinuousHandler)


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
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(shellExecute)


        TJS_BEGIN_NATIVE_METHOD_DECL(showVersion)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(showVersion)


        TJS_BEGIN_NATIVE_METHOD_DECL(terminate)
            KrkrRuntime::request_quit(param[0]->AsInteger());
            return TJS_S_OK;
        TJS_END_NATIVE_METHOD_DECL(terminate)


        TJS_BEGIN_NATIVE_METHOD_DECL(toActualColor)
            return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(toActualColor)


        TJS_BEGIN_NATIVE_METHOD_DECL(touchImages)
                return TJS_E_NOTIMPL;
        TJS_END_NATIVE_METHOD_DECL(touchImages)


        //===== PROPERTIES =====
        TJS_BEGIN_NATIVE_PROP_DECL(appDataPath)
        {
            TJS_BEGIN_NATIVE_PROP_GETTER
                {
                    tjs_string app_data_path;
                    KrkrRuntime::filesystem->get_appdata_directory(app_data_path);
                    *result = app_data_path.c_str();
                    return TJS_S_OK;
                }
            TJS_END_NATIVE_PROP_GETTER

            TJS_DENY_NATIVE_PROP_SETTER
        }
        TJS_END_NATIVE_PROP_DECL(appDataPath)


        TJS_BEGIN_NATIVE_PROP_DECL(dataPath)
        {
            TJS_BEGIN_NATIVE_PROP_GETTER
                {
                    tjs_string app_data_path;
                    KrkrRuntime::filesystem->get_appdata_directory(app_data_path);
                    *result = app_data_path.c_str();
                    return TJS_S_OK;
                }
            TJS_END_NATIVE_PROP_GETTER

            TJS_DENY_NATIVE_PROP_SETTER
        }
        TJS_END_NATIVE_PROP_DECL(dataPath)


        TJS_BEGIN_NATIVE_PROP_DECL(eventDisabled)
        {
            TJS_BEGIN_NATIVE_PROP_GETTER
            {
                *result = EventManager::is_event_enabled;
                return TJS_S_OK;
            }
            TJS_END_NATIVE_PROP_GETTER

            TJS_BEGIN_NATIVE_PROP_SETTER
            {
                EventManager::is_event_enabled = *param;
                return TJS_S_OK;
            }
            TJS_END_NATIVE_PROP_SETTER
        }
        TJS_END_NATIVE_PROP_DECL(eventDisabled)


        TJS_BEGIN_NATIVE_PROP_DECL(versionString)
        {
            TJS_BEGIN_NATIVE_PROP_GETTER
                {
                    tjs_string runtime_str;
                    KrkrRuntime::get_runtime_version(runtime_str);
                    *result = runtime_str.c_str();
                    return TJS_S_OK;
                }
            TJS_END_NATIVE_PROP_GETTER

            TJS_DENY_NATIVE_PROP_SETTER
        }
        TJS_END_NATIVE_STATIC_PROP_DECL(versionString)


        TJS_BEGIN_NATIVE_PROP_DECL(versionInformation)
        {
            TJS_BEGIN_NATIVE_PROP_GETTER
                {
                    tjs_string runtime_str;
                    KrkrRuntime::get_runtime_version_full(runtime_str);
                    *result = runtime_str.c_str();
                    return TJS_S_OK;
                }
            TJS_END_NATIVE_PROP_GETTER

            TJS_DENY_NATIVE_PROP_SETTER
        }
        TJS_END_NATIVE_STATIC_PROP_DECL(versionInformation)
    TJS_END_NATIVE_MEMBERS
}

tTJSNativeInstance *SystemNativeClass::CreateNativeInstance() {
    return nullptr;
}