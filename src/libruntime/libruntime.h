#pragma once

#include <map>
#include "interfaces/filesystem.h"
#include "interfaces/console.h"
#include "interfaces/sysfunc.h"

namespace LibRuntime {
    typedef struct RuntimeConfig {
        bool verbose;
        bool enable_console_output;
    } RuntimeConfig;

    class KrkrRuntime {
    public:
        static int start_runtime(int argc, char *argv[]);
        static void request_exit(int code);
        static bool get_argument(const tjs_string &name, tjs_string &result);
        static void set_argument(const tjs_string &name, const tjs_string &value);

        static void request_quit(int code);

        static Interfaces::IFileSystem *filesystem;
        static Interfaces::IConsole *console;
        static Interfaces::ISysFunc *sysfunc;

    private:
        static bool interpreter();
        static void parse_args(int argc, char *argv[]);
        static std::map<tjs_string, tjs_string> arguments;
        static bool quit_required;
        static int quit_code;
    };
}
