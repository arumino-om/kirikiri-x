//TODO: include関連を整理する
#include <tjsCommHead.h>
#include <tjsTypes.h>
#include "libruntime.h"
#include "messages.h"
#include <tjsError.h>
#include "script_manager.h"

using namespace LibRuntime;

// --- Init global variables ---
Interfaces::IFileSystem* KrkrRuntime::filesystem = new Interfaces::FileSystemFallbackImpl();
Interfaces::IConsole* KrkrRuntime::console = new Interfaces::ConsoleFallbackImpl();
Interfaces::ISysFunc* KrkrRuntime::sysfunc = new Interfaces::SysFuncFallbackImpl();
std::map<tjs_string, tjs_string> KrkrRuntime::arguments;
bool KrkrRuntime::quit_required = false;
int KrkrRuntime::quit_code = 0;

int KrkrRuntime::start_runtime(int argc, char *argv[]) {
    console->write(TJS_W("--- Kirikiri X Runtime ---\n"));
    console->write(TJS_W("Initializing runtime\n"));

    KrkrRuntime::parse_args(argc, argv);
    Messages::init_tjs_messages();
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), 1);

    KrkrRuntime::interpreter();

    return 0;
}

void KrkrRuntime::parse_args(int argc, char *argv[]) {
    char *name, *value;
    tjs_string name_s, value_s;
    for (int i = 0; i < argc; i++) {
        if (*argv[i] != '-') continue;

        name = strtok(argv[i], const_cast<const char*>("="));
        value = strtok(nullptr, const_cast<const char*>("="));

        TVPUtf8ToUtf16(name_s, name);
        if (value == nullptr) {
            KrkrRuntime::arguments.emplace(name_s, tjs_string(TJS_W("yes")));
        } else {
            TVPUtf8ToUtf16(value_s, value);
            KrkrRuntime::arguments.emplace(name_s, value_s);
        }
    }
}

bool KrkrRuntime::get_argument(const tjs_string &name, tjs_string &result) {
    if (auto iter = KrkrRuntime::arguments.find(name); iter != std::end(KrkrRuntime::arguments)) {
        result = iter->second;
        return true;
    }
    return false;
}

void KrkrRuntime::set_argument(const tjs_string& name, const tjs_string &value) {
    KrkrRuntime::arguments[name] = value;
}

bool KrkrRuntime::interpreter() {
    console->write(TJS_W("You are currently in interpreter mode. Type \"exit();\" to exit.\n"));
    while (!quit_required) {
        tjs_string readresult;
        console->write(TJS_W(">> "));
        console->readline(readresult);

        if (readresult == TJS_W("exit();")) break;

        try {
            ScriptManager::run(readresult);
        } catch (eTJSError &err) {
            console->error(TJS_W("[ERR] "));
            console->error(err.GetMessage().c_str());
            console->error(TJS_W("\n"));
        }
    }

    return true;
}

void KrkrRuntime::request_quit(int code = 0) {
    quit_required = true;
    quit_code = code;
}