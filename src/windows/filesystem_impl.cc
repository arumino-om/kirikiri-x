#include "filesystem_impl.h"
#include "localfile_stream.h"
#include <windows.h>
#include <shlwapi.h>

size_t WindowsFileSystem::get_current_directory(tjs_char *result) {
    DWORD buflen = GetCurrentDirectoryW(0, nullptr);
    if (result == nullptr) {
        return buflen;
    }

    DWORD written = GetCurrentDirectoryW(buflen, (LPWSTR)result);
    return written;
}

bool WindowsFileSystem::set_current_directory(const tjs_char *path) {
    BOOL result = SetCurrentDirectoryW((LPWSTR)path);
    return (bool)result;
}

tTJSBinaryStream *WindowsFileSystem::open(const tjs_char *path, tjs_uint32 flags) {
    return new WindowsLocalFileStream(path, flags);
}

bool WindowsFileSystem::file_exists(const tjs_char *path) {
    DWORD attr = GetFileAttributesW((LPCWSTR)path);
    return (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool WindowsFileSystem::directory_exists(const tjs_char *path) {
    DWORD attr = GetFileAttributesW((LPCWSTR)path);
    return (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

tjs_int WindowsFileSystem::get_maxpath_length() {
    return MAX_PATH;
}
