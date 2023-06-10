#pragma once
#include "interfaces/filesystem.h"

namespace LibRuntime {
    class KrkrRuntime {
    public:
        static int start_runtime();

        static IFileSystem *filesystem;
    };
}
