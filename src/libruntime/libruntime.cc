#include "tjs.h"
#include "tjsError.h"
#include "libruntime.h"
#include <iostream>
#include <script_manager.h>

int KrkrRuntime::start_runtime() {
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), true);

    try {
        ScriptManager::run(TJS_W("function hoge("));
    } catch (eTJSError &e) {
        std::wcerr << "Error Occured: " << e.GetMessage().AsStdWString() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Error" << std::endl;
    }
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), true);
    system("PAUSE");
    return 0;
}
