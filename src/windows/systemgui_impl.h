#pragma once
#include "interfaces/system_gui.h"

class WindowsSystemGUI: public LibRuntime::Interfaces::ISystemGUI {
public:
    int show_message_box(const wchar_t *message, const wchar_t *title, LibRuntime::Interfaces::MessageBoxType type) override;
};
