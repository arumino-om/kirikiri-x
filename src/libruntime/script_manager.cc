#include <tjs.h>
#include "script_manager.h"

using namespace LibRuntime;

// --- Init global variable ---
bool ScriptManager::initialized = false;
tTJS *ScriptManager::tjs_engine = nullptr;
ttstr ScriptManager::startup_script_name = TJS_W("startup.tjs");


bool ScriptManager::init(const ttstr &startup_script_name, const ttstr &encoding, int krkr_compatible) {
    if (initialized) return true;

    ScriptManager::tjs_engine = new tTJS;

    initialized = true;
    return true;
}


void ScriptManager::run(const ttstr &script) {
    ScriptManager::tjs_engine->ExecScript(script);
}