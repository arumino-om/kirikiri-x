#include "systemgui_impl.h"
#include <windows.h>

using msgboxType = LibRuntime::Interfaces::MessageBoxType;

int WindowsSystemGUI::show_message_box(const std::wstring &message, const std::wstring &title,
                                       LibRuntime::Interfaces::MessageBoxType type) {
    UINT msgType = 0;
    switch (type) {
        case msgboxType::MSGTYPE_INFO:
            msgType |= MB_ICONINFORMATION;
            break;

        case msgboxType::MSGTYPE_ERROR:
            msgType |= MB_ICONERROR;
            break;

        case msgboxType::MSGTYPE_WARNING:
            msgType |= MB_ICONWARNING;
            break;
    }
//    char *message_mb = nullptr;
//    char *title_mb = nullptr;
//    int convert_result_msg = WindowsUtils::wide2mb(message, message_mb, CP_ACP);
//    int convert_result_title = WindowsUtils::wide2mb(title, title_mb, CP_ACP);
//    if (convert_result_msg <= 0 || convert_result_title <= 0) return -1;

    int result = MessageBoxW(nullptr, message.c_str(), title.c_str(), msgType);
    return result;
}
