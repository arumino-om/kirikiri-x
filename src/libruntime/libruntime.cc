#include "tjs.h"
#include "libruntime.h"
#include "messages.h"
#include "tjsError.h"
#include <script_manager.h>
#include <iostream>

using namespace LibRuntime;

// --- Init global variables ---
IFileSystem* KrkrRuntime::filesystem = new FileSystemFallbackImpl();

int KrkrRuntime::start_runtime() {
    Messages::init_tjs_messages();
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), 1);

    system("PAUSE");
    return 0;
}
