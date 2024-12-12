#include "filepath_impl.h"
#include <unistd.h>

UnixFilePath::UnixFilePath(std::string exe_path) {
    TVPUtf8ToUtf16(this->exe_path, exe_path);
}


bool UnixFilePath::get_current_directory(tjs_string &result) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        TVPUtf8ToUtf16(result, cwd);
        return true;
    }
    return false;
}

bool UnixFilePath::set_current_directory(tjs_string &dir) {
    std::string dir_utf8;
    TVPUtf16ToUtf8(dir_utf8, dir);

    if (chdir(dir_utf8.c_str()) != 0) {
        return false;
    }
    return true;
}

bool UnixFilePath::get_home_directory(tjs_string &result) {
    std::string(getenv("HOME"));
    TVPUtf8ToUtf16(result, getenv("HOME"));
    return true;
}

bool UnixFilePath::get_exe_path(tjs_string &result) {
    result = this->exe_path;
    return true;
}
