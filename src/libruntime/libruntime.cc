#include "tjs.h"
#include "tjsError.h"
#include "libruntime.h"
#include <iostream>
#include <script_manager.h>

using namespace LibRuntime;

// --- Init global variables ---
IFileSystem* KrkrRuntime::filesystem = new FileSystemFallbackImpl();

int KrkrRuntime::start_runtime() {
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), true);

    system("PAUSE");
    return 0;
}
