#include "tjs.h"
#include "tjsError.h"
#include "libruntime.h"
#include <iostream>
#include <script_manager.h>

int KrkrRuntime::start_runtime() {
    tTJS *tjsengine = new tTJS();
    TJSSyntaxError.AssignMessage(TJS_W("Syntax Error"));

    try {
        tTJSVariant result;
        tjsengine->ExecScript(TJS_W("function te"), &result, nullptr, TJS_W("test code"));
        std::cout << "Result: " << (int)result << std::endl;
    } catch (eTJSError &e) {
        std::wcerr << "Error Occured: " << e.GetMessage().AsStdWString() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Error" << std::endl;
    }
    ScriptManager::init(TJS_W("startup.tjs"), TJS_W("UTF-8"), true);
    system("PAUSE");
    return 0;
}
