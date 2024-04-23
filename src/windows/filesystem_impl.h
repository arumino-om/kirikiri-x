#pragma once
#include "interfaces/filesystem.h"

class WindowsFileSystem: public LibRuntime::Interfaces::IFileSystem {
public:
    size_t get_current_directory(tjs_char *result) override;
    bool set_current_directory(const tjs_char *path) override;

    tTJSBinaryStream *open(const tjs_char *path, tjs_uint32 flags) override;

    bool file_exists(const tjs_char *path) override;
    bool directory_exists(const tjs_char *path) override;

    int get_maxpath_length() override;
};
