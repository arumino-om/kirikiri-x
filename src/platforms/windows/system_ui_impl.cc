#include "system_ui_impl.h"
#include <iostream>
#include <libruntime.h>

#include "resource.h"
#include <windows.h>

void WindowsSystemUI::show_dialog(const ttstr& title, const ttstr& message) {
    MessageBoxW(nullptr, message.c_str(), title.c_str(), MB_OK | MB_ICONINFORMATION);
}

LRESULT WindowsSystemUI::DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    ttstr about_text;
    switch (uMsg) {
    case WM_INITDIALOG:
        about_text = LibRuntime::KrkrRuntime::get_about_text();
        about_text.Replace(TJS_W("\n"), TJS_W("\r\n")); // Windows だと \n だけでは改行されない
        SetDlgItemText(hwndDlg, IDC_ABOUT_CONTENT, about_text.c_str());
        return TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCLOSE) {
            EndDialog(hwndDlg, LOWORD(wParam));
            return TRUE;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, 0);
        return TRUE;
    default:
        break;
    }
    return FALSE;
}


void WindowsSystemUI::show_version_dialog()
{
    DialogBox(nullptr, MAKEINTRESOURCE(IDD_KRKRX_ABOUT), nullptr, (DLGPROC)WindowsSystemUI::DialogProc);
}
