#include <tjs.h>
#include <tjsError.h>
#include "script_manager.h"

// --- Init global variable ---
bool ScriptManager::initialized = false;
tTJS *ScriptManager::tjs_engine = nullptr;


void ScriptManager::init(const ttstr& startup_script_name, const ttstr& encoding, bool debug) {
    if (initialized) return;
    init_message();
    ScriptManager::tjs_engine = new tTJS;

    initialized = true;
}

void ScriptManager::init_message() {
    TJSSyntaxError.AssignMessage(TJS_W("Syntax Error"));
}

void ScriptManager::run(const ttstr& script) {
    ScriptManager::tjs_engine->ExecScript(script);
}