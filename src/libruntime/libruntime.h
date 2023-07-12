#pragma once
#include "interfaces/filesystem.h"
#include "interfaces/console.h"

namespace LibRuntime {
    class KrkrRuntime {
    public:
        static int start_runtime();

        static IFileSystem *filesystem;
        static IConsole *console;
    };
}
