#include "systemgui_impl.h"
#include <windows.h>

// ERROR 定数が定義されていると MessageBoxType::ERROR が 0 に置き換わってしまう
#ifdef ERROR
#undef ERROR
#endif

int WindowsSystemGUI::show_message_box(const wchar_t *message, const wchar_t *title, LibRuntime::Interfaces::MessageBoxType type) {
    UINT msgType = 0;
    switch (type) {
        case LibRuntime::Interfaces::INFO:
            msgType |= MB_ICONINFORMATION;
            break;

        case LibRuntime::Interfaces::ERROR:
            msgType |= MB_ICONERROR;
            break;

        case LibRuntime::Interfaces::WARNING:
            msgType |= MB_ICONWARNING;
            break;
    }
    int result = MessageBoxW(NULL, message, title, msgType);
    return result;
}
