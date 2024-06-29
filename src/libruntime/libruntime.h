#pragma once
#include "interfaces/filesystem.h"
#include "interfaces/console.h"

namespace LibRuntime {
    typedef struct RuntimeConfig {
        bool verbose;
        bool enable_console_output;
    } RuntimeConfig;

    class KrkrRuntime {
    public:
        static int start_runtime();
        static void request_exit(int code);

        static Interfaces::IFileSystem *filesystem;
        static Interfaces::IConsole *console;

    private:
        static bool interpreter();
    };
}
