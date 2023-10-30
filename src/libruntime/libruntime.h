#pragma once
#include "interfaces/filesystem.h"
#include "interfaces/console.h"
#include "interfaces/system_gui.h"

namespace LibRuntime {
    typedef struct RuntimeConfig {
        bool verbose;
        bool enable_console_output;
    } RuntimeConfig;

    class KrkrRuntime {
    public:
        static int start_runtime();

        static Interfaces::IFileSystem *filesystem;
        static Interfaces::IConsole *console;
        static Interfaces::ISystemGUI *system_gui;

    private:
        static bool interpreter();
    };
}
