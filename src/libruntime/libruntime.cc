#include "tjs.h"
#include "libruntime.h"
#include "messages.h"
#include "tjsError.h"
#include <script_manager.h>
#include <iostream>

using namespace LibRuntime;

// --- Init global variables ---
IFileSystem* KrkrRuntime::filesystem = new FileSystemFallbackImpl();
IConsole* KrkrRuntime::console = new ConsoleFallbackImpl();

int KrkrRuntime::start_runtime() {
    console->write(TJS_W("--- Kirikiri X Runtime ---\n"));
    console->write(TJS_W("Initializing runtime\n"));

    Messages::init_tjs_messages();
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), 1);


    return 0;
}
