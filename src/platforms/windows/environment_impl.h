#pragma once
#include <interfaces/environment.h>

class WindowsEnvironment: public LibRuntime::Interfaces::IEnvironment {
public:
    bool get_execution_path(ttstr &out) override;
    bool get_personal_path(ttstr &out) override;
    bool get_saved_games_path(ttstr &out) override;
    bool get_platform_name(ttstr &out) override;
    bool get_os_name(ttstr &os_name) override;
};