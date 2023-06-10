#include "filesystem_impl.h"
#include <windows.h>

bool WindowsFileSystem::get_current_directory(wchar_t *result, size_t result_size) {
    GetCurrentDirectoryW(result_size, static_cast<LPWSTR>(result));
    return true;
}
bool WindowsFileSystem::set_current_directory(const wchar_t *path) {
    SetCurrentDirectoryW(static_cast<LPWSTR>(const_cast<wchar_t*>(path)));
    return true;
}
std::wfstream WindowsFileSystem::get_file(const wchar_t *path) {
    return {path};
}
int WindowsFileSystem::get_maxpath_length() {
    return MAX_PATH;
}