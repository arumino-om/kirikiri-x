#pragma once
#include <interfaces/environment.h>

class LinuxEnvironemnt: public LibRuntime::Interfaces::IEnvironment {
public:
    ttstr get_env(const ttstr &envname) override;
    void set_env(const ttstr &envname, const ttstr &value) override;
    ttstr get_execution_path() override;
};
