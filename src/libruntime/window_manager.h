#pragma once
#include "native_instances/window_instance.h"

namespace LibRuntime {
    class WindowManager {
    public:
        static void register_window(NativeInstances::WindowNativeInstance *window);
        static void unregister_window(NativeInstances::WindowNativeInstance *window);
        static bool has_windows();

    private:
        static std::vector<NativeInstances::WindowNativeInstance*> windows;
        static NativeInstances::WindowNativeInstance *main_window;
    };
}
