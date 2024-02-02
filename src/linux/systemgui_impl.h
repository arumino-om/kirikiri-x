#pragma once
#include <string>
#include "interfaces/system_gui.h"

class LinuxSystemGUI: public LibRuntime::Interfaces::ISystemGUI {
public:
    int show_message_box(const std::wstring &message, const std::wstring &title, LibRuntime::Interfaces::MessageBoxType type) override;
};
