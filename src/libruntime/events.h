#pragma once
#include <iostream>
#include <tjs.h>

namespace LibRuntime {
    class Events {
    public:
        static void add_continuous_handler(tTJSVariantClosure closure);
        static void remove_continuous_handler(tTJSVariantClosure closure);
        static void call_continuous_handler();

    private:
        static std::vector<tTJSVariantClosure> continuous_handlers;
    };
}
