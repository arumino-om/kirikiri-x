#include "filesystem_impl.h"
#include "console_impl.h"
#include "SDL.h"
#include "libruntime.h"
#include <iostream>
#include <windows.h>
#include <fcntl.h>

void alloc_console() {
    if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
#if DEBUG
        AllocConsole();
#endif
    }
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
}

int main(int argv, char** args) {
    alloc_console();
    setlocale(LC_ALL,"");

    LibRuntime::KrkrRuntime::filesystem = new WindowsFileSystem();
//    LibRuntime::KrkrRuntime::console = new WindowsConsole();
    LibRuntime::KrkrRuntime::start_runtime();

#if DEBUG
    system("PAUSE");
    FreeConsole();
#endif
}