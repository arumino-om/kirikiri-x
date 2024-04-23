#pragma once
#include "tjs.h"
#include "tjsError.h"
#include <windows.h>

class WindowsLocalFileStream : public tTJSBinaryStream {
private:
    HANDLE _handle;

public:
    WindowsLocalFileStream(const ttstr &filename, tjs_uint32 flag);
    ~WindowsLocalFileStream() override;

    tjs_uint64 Seek(tjs_int64 offset, tjs_int whence) override;
    tjs_uint Read(void *buffer, tjs_uint read_size) override;
    tjs_uint Write(const void *buffer, tjs_uint write_size) override;

    void SetEndOfStorage() override;

    tjs_uint64 GetSize() override;

    [[nodiscard]]
    HANDLE GetHandle() const { return _handle; }
};