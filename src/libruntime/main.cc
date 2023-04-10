#include <iostream>
#include "tjs.h"
#include "tjsError.h"

int main() {
    tTJS *tjsengine = new tTJS();
    try {
        tTJSVariant result;
        tjsengine->ExecScript(TJS_W("function test(x, y) { return x*y; } return test(4,6);"), &result, NULL, TJS_W("test code"));
        std::cout << "Result: " << (int)result << std::endl;
    } catch (eTJSError &e) {
        std::cerr << "Error occured: " << e.GetMessage().c_str() << std::endl;
    } catch (...) {
        std::cerr << "Unknown Error" << std::endl;
    }
    return 0;
}
