#include <iostream>
#include "tjs.h"
#include "tjsError.h"
#include "coreutils/uni_cp932.h"
#include "libruntime.h"

void GCOT::ExceptionPrint(const TJS::tjs_char *message) {
    tjs_size sjis_length = UnicodeToSJISString(message, NULL);
    tjs_nchar nchar[sjis_length + 1];
    tjs_size result = UnicodeToSJISString(message, nchar, sjis_length);

    if (result == (tjs_size)-1) {
        std::cerr << "[system][err] Internal error occured when converting Unicode->SJIS" << std::endl;
    } else {
        nchar[sjis_length] = '\0';
        std::cerr << "[libruntime][err] " << nchar << std::endl;
    }
}
void GCOT::Print(const TJS::tjs_char *message) {
    tjs_size sjis_length = UnicodeToSJISString(message, NULL);
    tjs_nchar nchar[sjis_length + 1];
    tjs_size result = UnicodeToSJISString(message, nchar, sjis_length);

    if (result == (tjs_size)-1) {
        std::cerr << "[system][err] Internal error occured when converting Unicode->SJIS" << std::endl;
    } else {
        nchar[sjis_length] = '\0';
        std::cout << "[libruntime][cns] " << nchar << std::endl;
    }
}

int init_tjs(tTJS *tjsEngine);

int start() {
    tTJS *tjsengine = new tTJS();
    init_tjs(tjsengine);

    try {
        tTJSVariant result;
        tjsengine->ExecScript(TJS_W("function te"), &result, nullptr, TJS_W("test code"));
        std::cout << "Result: " << (int)result << std::endl;
    } catch (eTJSError &e) {
        std::wcerr << "Error Occured: " << e.GetMessage().AsStdString() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Error" << std::endl;
    }

    system("PAUSE");
    return 0;
}

int init_tjs(tTJS *tjsEngine) {
    std::cout << "--- Kirikiri S Runtime Initialize ---" << std::endl;
//    setlocale(LC_ALL, "ja-JP.UTF-8");
    setlocale(LC_CTYPE, "");
    std::cout << "Current Locale: " << setlocale(LC_ALL, NULL) << std::endl;
    std::cout << "Initializing TJS Scripting engine..." << std::endl;

    TJSSyntaxError.AssignMessage(TJS_W("文法エラーです"));


    iTJSConsoleOutput *out = new GCOT();
    tjsEngine->SetConsoleOutput(out);

    std::cout << "Initialized TJS Scripting engine." << std::endl;

    std::cout << "-------------------------------------" << std::endl;

    tjsEngine->OutputToConsole(TJS_W("hこんにちはHello"));

    return 0;
}