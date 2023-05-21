#include "filesystem.h"
#include "libruntime.h"

int main() {
    LibRuntime::KrkrRuntime::filesystem = new WindowsFileSystem();
    LibRuntime::KrkrRuntime::start_runtime();
}