#pragma once
#include <tjs.h>

class ScriptManager {
public:
    static void init(ttstr startup_script_name, ttstr encoding, bool debug);

private:
    static bool debug_mode;
    static ttstr file_encoding;
    static tTJS tjs_engine;
};
