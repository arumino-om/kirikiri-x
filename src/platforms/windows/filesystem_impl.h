#pragma once
#include "interfaces/filesystem.h"

class WindowsFileSystem: public LibRuntime::Interfaces::IFileSystem {
public:
    size_t get_current_directory(tjs_char *result) override;
    bool set_current_directory(const tjs_char *path) override;

    tTJSBinaryStream *open(const tjs_char *path, tjs_uint32 flags) override;

    bool file_exists(const tjs_char *path) override;
    bool directory_exists(const tjs_char *path) override;

    tjs_int get_maxpath_length() override;
    bool get_home_directory(tjs_string &result) override;
    bool get_appdata_directory(tjs_string &result) override;
    bool get_savedata_directory(tjs_string &result) override;

    bool path_combine(const tjs_string &path1, const tjs_string &path2, tjs_string &result) override;
};
