#include "events.h"

using namespace LibRuntime;

void Events::add_continuous_handler(TJS::tTJSVariantClosure closure) {
    continuous_handlers.push_back(closure);
}

void Events::remove_continuous_handler(TJS::tTJSVariantClosure closure) {
    std::vector<tTJSVariantClosure>::iterator i;
    i = std::find(continuous_handlers.begin(), continuous_handlers.end(), closure);
    if (i != continuous_handlers.end()) continuous_handlers.erase(i);
}

void Events::call_continuous_handler() {
    for (const auto& e : continuous_handlers) {
        e.FuncCall(0, nullptr, nullptr, nullptr, 1, /*vtick*/0, nullptr);
    }
}