#pragma once
#include <tjs.h>

class ScriptManager {
public:
    static void init(const ttstr& startup_script_name, const ttstr& encoding, bool debug);
    static void init_message();
    static void run(const ttstr& script);

private:
    static bool debug_mode;
    static ttstr file_encoding;
    static tTJS *tjs_engine;
    static bool initialized;
};