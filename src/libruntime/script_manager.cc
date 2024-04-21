#include <tjsTypes.h>
#include "native_objects/minimal.h"
#include "script_manager.h"

using namespace LibRuntime;

// --- Init global variable ---
bool ScriptManager::initialized = false;
tTJS *ScriptManager::tjs_engine = nullptr;
ttstr ScriptManager::startup_script_name = TJS_W("startup.tjs");


bool ScriptManager::init(const ttstr &startup_script_name, const ttstr &encoding, int krkr_compatible) {
    // --- Check if already initialized ---
    if (initialized) return true;

    // --- Initialize TJS ---
    ScriptManager::tjs_engine = new tTJS;
    if (ScriptManager::tjs_engine == nullptr) return false;

    // --- 吉里吉里互換モード毎の初期化 ---
    switch (krkr_compatible) {
        default:
        case 0:
            // 吉里吉里X
            ScriptManager::tjs_engine->SetPPValue(TJS_W("kirikirix"), 1);
            break;

        case 1:
            // 吉里吉里Z
            ScriptManager::tjs_engine->SetPPValue(TJS_W("kirikiriz"), 1);
            break;

        case 2:
            // 吉里吉里2
            ScriptManager::tjs_engine->SetPPValue(TJS_W("kirikiri2"), 1);
            break;
    }

    // --- Register native objects ---
    iTJSDispatch2 *global = ScriptManager::tjs_engine->GetGlobalNoAddRef();
    iTJSDispatch2 *dsp;
    tTJSVariant val;
    #define REGISTER_OBJECT(classname, native_classname) \
        dsp = new native_classname(); \
        val = tTJSVariant(dsp/*, dsp*/); \
        dsp->Release(); \
        global->PropSet(TJS_MEMBERENSURE|TJS_IGNOREPROP, TJS_W(#classname), NULL, \
            &val, global);
    REGISTER_OBJECT(mini, NativeObjects::MinimalNativeClass);

    // --- Finalize ---
    initialized = true;
    return true;
}


void ScriptManager::run(const ttstr &script) {
    ScriptManager::tjs_engine->ExecScript(script);
}