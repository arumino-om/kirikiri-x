#include "filesystem_impl.h"
#include <windows.h>

size_t WindowsFileSystem::get_current_directory(tjs_char *result) {
    return 0;
}

bool WindowsFileSystem::set_current_directory(const tjs_char *path) {
    return false;
}

tTJSBinaryStream *WindowsFileSystem::open(const tjs_char *path, tjs_uint32 flags) {
    return nullptr;
}

bool WindowsFileSystem::file_exists(const tjs_char *path) {
    return false;
}

bool WindowsFileSystem::directory_exists(const tjs_char *path) {
    return false;
}

int WindowsFileSystem::get_maxpath_length() {
    return 0;
}
