#include "filesystem_impl.h"
#include "localfile_stream.h"
#include <windows.h>
#include <pathcch.h>
#include <ShlObj_core.h>

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

bool WindowsFileSystem::get_home_directory(tjs_string &result) {
    PWSTR path = nullptr;
    if (HRESULT hr = SHGetKnownFolderPath(FOLDERID_Profile, 0, nullptr, &path); hr != S_OK) {
        result.clear();
        return false;
    }

    result = path;

    CoTaskMemFree(path);
    return true;
}

bool WindowsFileSystem::get_appdata_directory(tjs_string &result) {
    PWSTR path = nullptr;
    if (const HRESULT hr = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path); hr != S_OK) {
        result.clear();
        return false;
    }

    result = path;

    CoTaskMemFree(path);
    return true;
}

bool WindowsFileSystem::path_combine(const tjs_char *path1, const tjs_char *path2, tjs_char *out) {
    HRESULT result = PathCchCombine((PWSTR)out, sizeof(out), (PCWSTR)path1, (PCWSTR)path2);
    return result == S_OK;
}
