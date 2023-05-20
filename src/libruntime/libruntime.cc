#include "tjs.h"
#include "tjsError.h"
#include "libruntime.h"
#include <iostream>
#include <script_manager.h>

int KrkrRuntime::start_runtime(ttstr root_dir) {
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), true);


    system("PAUSE");
    return 0;
}
