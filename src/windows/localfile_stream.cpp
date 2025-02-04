#include "localfile_stream.h"

WindowsLocalFileStream::WindowsLocalFileStream(const ttstr &filename, tjs_uint32 flag) {
    _handle = INVALID_HANDLE_VALUE;
    tjs_uint32 access_flag = flag & TJS_BS_ACCESS_MASK;

    DWORD desired_access, creation_disposition;
    switch (access_flag) {
        case TJS_BS_READ:
            desired_access = GENERIC_READ;
            creation_disposition = OPEN_EXISTING;
            break;

        case TJS_BS_WRITE:
            desired_access = GENERIC_WRITE;
            creation_disposition = CREATE_ALWAYS;
            break;

        case TJS_BS_APPEND:
            desired_access = GENERIC_WRITE;
            creation_disposition = OPEN_ALWAYS;
            break;

        case TJS_BS_UPDATE:
            desired_access = GENERIC_READ | GENERIC_WRITE;
            creation_disposition = OPEN_EXISTING;
            break;

        default:
            throw eTJSError(TJS_W("Unknown access flag"));
    }

    _handle = CreateFile((wchar_t*)filename.c_str(), desired_access, FILE_SHARE_READ, nullptr, creation_disposition, FILE_ATTRIBUTE_NORMAL, nullptr);

    if (access_flag == TJS_BS_APPEND) {
        WindowsLocalFileStream::Seek(0, TJS_BS_SEEK_END);
    }
}

WindowsLocalFileStream::~WindowsLocalFileStream() {
    if (_handle != INVALID_HANDLE_VALUE) CloseHandle(_handle);
}

tjs_uint64 WindowsLocalFileStream::Seek(tjs_int64 offset, tjs_int whence) {
    DWORD move_method = FILE_CURRENT;
    switch (whence) {
        case TJS_BS_SEEK_SET:
            move_method = FILE_BEGIN;
            break;

        case TJS_BS_SEEK_END:
            move_method = FILE_END;
            break;

        default:
            move_method = FILE_CURRENT;
            break;
    }

    LARGE_INTEGER large_int;
    large_int.QuadPart = offset;
    PLARGE_INTEGER new_fileptr;

    SetFilePointerEx(_handle, large_int, new_fileptr, move_method);

    return new_fileptr->QuadPart;
}

tjs_uint WindowsLocalFileStream::Read(const void *buffer, tjs_uint read_size) {
    DWORD retval = 0;
    ReadFile(_handle, buffer, read_size, &retval, nullptr);
    return retval;
}

tjs_uint WindowsLocalFileStream::Write(void *buffer, tjs_uint write_size) {
    DWORD retval = 0;
    WriteFile(_handle, buffer, write_size, &retval, nullptr);
    return retval;
}

tjs_uint64 WindowsLocalFileStream::GetSize() {
    PLARGE_INTEGER filesize;
    GetFileSizeEx(_handle, filesize);
    return filesize->QuadPart;
}

void WindowsLocalFileStream::SetEndOfStorage() {
    SetEndOfFile(_handle);
}
