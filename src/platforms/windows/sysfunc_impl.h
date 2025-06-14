#pragma once
#include <interfaces/sysfunc.h>

#include "interfaces/filesystem.h"

class WindowsSysFunc: public LibRuntime::Interfaces::ISysFunc {
public:
    void execute(const tjs_char *program, const tjs_char *params) override;
    bool create_app_lock(const tjs_char *lockname) override;
    unsigned long long get_tick_time() override;
    ttstr get_uuid() override;
};
