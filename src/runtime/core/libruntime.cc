//TODO: include関連を整理する
#include <tjsCommHead.h>
#include <tjsTypes.h>
#include "libruntime.h"
#include "messages.h"
#include "event_manager.h"
#include <tjsError.h>
#include "script_manager.h"
#include "window_manager.h"

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
    Messages::init_libruntime_messages();
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), 1);

    KrkrRuntime::interpreter();

    if (WindowManager::has_windows()) {
        SDL_Event event;
        while (true) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    return 0;
                }
                EventManager::dispatch_all_events();
            }
        }
    }

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

void KrkrRuntime::get_runtime_version(tjs_string &verstr) {
    ttstr version_major(KrkrRuntime::LIBRUNTIME_VERSION_MAJOR);
    ttstr version_minor(KrkrRuntime::LIBRUNTIME_VERSION_MINOR);
    ttstr version_patch(KrkrRuntime::LIBRUNTIME_VERSION_PATCH);

    ttstr verstr2 = version_major + TJS_W(".") + version_minor + TJS_W(".") + version_patch;
    verstr = verstr2.AsStdString();
}

void KrkrRuntime::get_runtime_version_full(tjs_string &verstr) {
    tjs_string runtime_version;
    KrkrRuntime::get_runtime_version(runtime_version);
    verstr = TJS_W("Kirikiri X Runtime ") + runtime_version;
}

bool KrkrRuntime::interpreter() {
    console->write(Messages::LRInterpreterMode);
    while (!quit_required) {
        LibRuntime::EventManager::dispatch_continuous_event();
        tjs_string readresult;
        console->write(TJS_W(">> "));
        console->readline(readresult);

        if (readresult == TJS_W("exit();")) break;

        try {
            // auto res = ScriptManager::eval(readresult);
            // switch (res.Type()) {
            // case tvtObject:
            //     console->write(TJS_W("Object"));
            //     break;
            // case tvtVoid:
            //     break;
            // default:
            //     res.ToString();
            //     console->write(res.GetString());
            //     break;
            // }
            // console->write(TJS_W("\n"));
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