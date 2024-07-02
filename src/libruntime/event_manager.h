#pragma once
#include <algorithm>
#include <tjsVariant.h>
#include <vector>

#include "tjsTypes.h"

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
