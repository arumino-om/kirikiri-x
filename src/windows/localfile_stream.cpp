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
    return 0;
}

tjs_uint WindowsLocalFileStream::Read(void *buffer, tjs_uint read_size) {
    return 0;
}

tjs_uint WindowsLocalFileStream::Write(const void *buffer, tjs_uint write_size) {
    return 0;
}

tjs_uint64 WindowsLocalFileStream::GetSize() {
    return 0;
}

void WindowsLocalFileStream::SetEndOfStorage() {
    tTJSBinaryStream::SetEndOfStorage();
}
