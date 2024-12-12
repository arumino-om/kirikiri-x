#pragma once
#include "libruntime.h"

class UnixFilePath : public LibRuntime::Interfaces::IFilePath {
public:
    UnixFilePath(std::string exe_path);
    bool get_current_directory(tjs_string &result) override;
    bool set_current_directory(tjs_string &dir) override;

    bool get_home_directory(tjs_string &result) override;
    bool get_exe_path(tjs_string &result) override;

private:
    tjs_string exe_path;
};
