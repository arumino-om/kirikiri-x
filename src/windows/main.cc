#include "SDL.h"
#include "libruntime.h"
#include "systemgui_impl.h"
#include "console_impl.h"

int main(int argv, char** args) {
    LibRuntime::KrkrRuntime::console = new WindowsConsole();
    LibRuntime::KrkrRuntime::system_gui = new WindowsSystemGUI();

    LibRuntime::KrkrRuntime::start_runtime();

#if DEBUG
    system("PAUSE");
//    FreeConsole();
#endif

    return 0;
}