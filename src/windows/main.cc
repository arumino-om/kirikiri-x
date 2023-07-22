#include "filesystem_impl.h"
#include "console_impl.h"
#include "SDL.h"
#include "libruntime.h"
#include <iostream>
#include <windows.h>
#include <fcntl.h>

void alloc_console() {
    AllocConsole();

    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int out_console_handle = _open_osfhandle(reinterpret_cast<intptr_t>(out_handle), _O_TEXT);
    *stdout = *_fdopen(out_console_handle, "w");
    setvbuf(stdout, nullptr, _IONBF, 0);

    HANDLE err_handle = GetStdHandle(STD_ERROR_HANDLE);
    int err_console_handle = _open_osfhandle(reinterpret_cast<intptr_t>(err_handle), _O_TEXT);
    *stderr = *_fdopen(err_console_handle, "w");
    setvbuf(stderr, nullptr, _IONBF, 0);
}

int main(int argv, char** args) {
#if DEBUG
    alloc_console();
#endif
    LibRuntime::KrkrRuntime::filesystem = new WindowsFileSystem();
    LibRuntime::KrkrRuntime::console = new WindowsConsole();
    LibRuntime::KrkrRuntime::start_runtime();

#if DEBUG
    system("PAUSE");
    FreeConsole();
#endif
}