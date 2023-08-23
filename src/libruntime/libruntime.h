#pragma once
#include "interfaces/filesystem.h"
#include "interfaces/console.h"

namespace LibRuntime {
    class KrkrRuntime {
    public:
        static int start_runtime();

        static Interfaces::IFileSystem *filesystem;
        static Interfaces::IConsole *console;

    private:
        static bool interpreter();
    };
}
