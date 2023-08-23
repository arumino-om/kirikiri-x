#include "tjs.h"
#include "libruntime.h"
#include "messages.h"
#include "tjsError.h"
#include <script_manager.h>
#include <iostream>

using namespace LibRuntime;

// --- Init global variables ---
Interfaces::IFileSystem* KrkrRuntime::filesystem = new Interfaces::FileSystemFallbackImpl();
Interfaces::IConsole* KrkrRuntime::console = new Interfaces::ConsoleFallbackImpl();

int KrkrRuntime::start_runtime() {
    console->write(TJS_W("--- Kirikiri X Runtime ---\n"));
    console->write(TJS_W("Initializing runtime\n"));

    Messages::init_tjs_messages();
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), 1);

    KrkrRuntime::interpreter();

    return 0;
}

bool KrkrRuntime::interpreter() {
    console->write(TJS_W("You are currently in interpreter mode. Type \"exit();\" to exit.\n"));
    while (true) {
        const tjs_char *readresult = nullptr;
        console->write(TJS_W(">> "));
        console->readline(readresult);

        if (wcscmp(readresult, TJS_W("exit();")) == 0) break;

        try {
            ScriptManager::run(readresult);
        } catch (eTJSError &err) {
            console->error(TJS_W("[ERR] "));
            console->error(err.GetMessage().c_str());
            console->error(TJS_W("\n"));
        }

        delete readresult;
    }
}