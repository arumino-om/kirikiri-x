#pragma once
#include "interfaces/filesystem.h"

class WindowsFileSystem: public LibRuntime::IFileSystem {
public:
    bool get_current_directory(wchar_t *result, size_t result_size) override;
    bool set_current_directory(const wchar_t *path) override;

    std::wfstream get_file(const wchar_t* path) override;
    int get_maxpath_length() override;
};
