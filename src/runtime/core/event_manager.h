#pragma once
#include "tjsVariant.h"
#include <vector>
#include <algorithm>

#include "native_instances/window_instance.h"

namespace LibRuntime {
    class EventManager {
    public:
        static bool init();

        static void add_continuous_handler(tTJSVariantClosure clo);
        static void remove_continuous_handler(tTJSVariantClosure clo);

        static void add_window_instance(NativeInstances::WindowNativeInstance *instance);
        static void remove_window_instance(NativeInstances::WindowNativeInstance *instance);

        static void dispatch_continuous_event();
        static void dispatch_window_update_event();
        static void dispatch_all_events();

        static bool is_event_enabled;

    private:
        static std::vector<tTJSVariantClosure> continuous_handlers;
        static std::vector<NativeInstances::WindowNativeInstance*> window_instances;
    };
}
