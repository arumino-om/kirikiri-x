#pragma once
#include "tjsCommHead.h"
#include "tjsError.h"

namespace LibRuntime {
    class Messages {
    public:
        static bool init_tjs_messages();
        static bool init_libruntime_messages();

        static tTJSMessageHolder LRInterpreterMode;
    };
}