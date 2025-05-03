#pragma once
#include "interfaces/system_ui.h"
#include <windows.h>

#ifdef IS_MSVC
#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

class WindowsSystemUI: public LibRuntime::Interfaces::ISystemUI {
public:
    void show_dialog(const ttstr& title, const ttstr& message) override;
    void show_version_dialog() override;

private:
    static LRESULT WINAPI DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
