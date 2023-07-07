#include "filesystem_impl.h"
#include "SDL.h"
#include "libruntime.h"
#include <iostream>
#include <windows.h>
#include <codecvt>

int main(int argv, char** args) {
    std::ios_base::sync_with_stdio(false);
    std::wcout.imbue(std::locale{std::locale{},new std::codecvt_utf8_utf16<wchar_t>{}});

    LibRuntime::KrkrRuntime::filesystem = new WindowsFileSystem();
    LibRuntime::KrkrRuntime::start_runtime();
}