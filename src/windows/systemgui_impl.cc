#include "systemgui_impl.h"
#include "windows_utils.h"
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
    char *message_mb = nullptr;
    char *title_mb = nullptr;
    int convert_result_msg = WindowsUtils::wide2mb(message, message_mb, CP_ACP);
    int convert_result_title = WindowsUtils::wide2mb(title, title_mb, CP_ACP);
    if (convert_result_msg <= 0 || convert_result_title <= 0) return -1;

    int result = MessageBoxA(NULL, message_mb, title_mb, msgType);
    return result;
}
