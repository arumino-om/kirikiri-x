#pragma once

#include <map>
#include "interfaces/filesystem.h"
#include "interfaces/console.h"

namespace LibRuntime {
    typedef struct RuntimeConfig {
        bool verbose;
        bool enable_console_output;
    } RuntimeConfig;

    class KrkrRuntime {
    public:
        static int start_runtime(int argc, char *argv[]);
        static void request_exit(int code);
        static bool get_argument(tjs_string name, tjs_string &result);

        static Interfaces::IFileSystem *filesystem;
        static Interfaces::IConsole *console;

    private:
        static bool interpreter();
        static void parse_args(int argc, char *argv[]);
        static std::map<tjs_string, tjs_string> arguments;
    };
}
