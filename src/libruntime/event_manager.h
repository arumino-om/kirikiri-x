#pragma once
#include "tjsVariant.h"
#include <vector>

namespace LibRuntime {
    class EventManager {
    public:
        static bool init();

        static void add_continuous_handler(tTJSVariantClosure clo);
        static void remove_continuous_handler(tTJSVariantClosure clo);

        static void call_event(int event_id);

    private:
        static std::vector<tTJSVariantClosure> continuous_handlers;
    };
}
