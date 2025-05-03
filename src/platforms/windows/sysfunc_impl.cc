#include "sysfunc_impl.h"
#include <windows.h>

typedef void (WINAPI *RtlGetVersionFunc)(OSVERSIONINFOEX* );

void WindowsSysFunc::execute(const tjs_char* program, const tjs_char* params)
{
    tjs_string system_text;
    system_text += program;
    if (params != nullptr) {
        system_text += TJS_W(" ");
        system_text += params;
    }

    std::string narrow_text;
    TVPUtf16ToUtf8(narrow_text, system_text);
    system(narrow_text.c_str());
}

bool WindowsSysFunc::create_app_lock(const tjs_char* lockname)
{
    return true;
}

void WindowsSysFunc::get_os_name(tjs_string& os_name)
{
    RTL_OSVERSIONINFOEXW osvi;
    ZeroMemory(&osvi, sizeof(RTL_OSVERSIONINFOEXW));
    osvi.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);
    ttstr osname;

    const auto dll = LoadLibraryW(L"ntdll.dll");
    if (dll == nullptr) {
        os_name = TJS_W("Microsoft Windows");
    }


    auto func = reinterpret_cast<RtlGetVersionFunc>(GetProcAddress(dll, "RtlGetVersion"));
    if (!func) {
        FreeLibrary(dll);
        os_name = TJS_W("Microsoft Windows");
    }

    func(&osvi);
    FreeLibrary(dll);
    osname = TJS_W("Microsoft Windows ");
    switch (osvi.dwPlatformId)
    {
    case VER_PLATFORM_WIN32s:
        osname += TJS_W("32s");
        break;

    case VER_PLATFORM_WIN32_WINDOWS:
        osname += TJS_W("9x");
        break;

    case VER_PLATFORM_WIN32_NT:
        osname += TJS_W("NT");
        break;
    default:
        osname += TJS_W("Unknown");
    }
    osname += TJS_W(" ");
    osname += std::to_wstring(osvi.dwMajorVersion);
    osname += TJS_W(".");
    osname += std::to_wstring(osvi.dwMinorVersion);
    osname += TJS_W(".");
    osname += std::to_wstring(osvi.dwBuildNumber);
    osname += TJS_W(" (");
    if (osvi.wProductType == VER_NT_WORKSTATION) {
        osname += TJS_W("Workstation");
    } else {
        osname += TJS_W("Server");
    }
    osname += TJS_W(")");
    os_name = osname.AsStdString();
}

unsigned long long WindowsSysFunc::get_tick_time()
{
    return GetTickCount64();
}

ttstr WindowsSysFunc::get_uuid()
{
    UUID uuid_win;
    RPC_CSTR uuid_str;
    UuidCreate(&uuid_win);
    UuidToStringA(&uuid_win, &uuid_str);

    ttstr result = reinterpret_cast<const char*>(uuid_str);
    RpcStringFreeA(&uuid_str);
    return result;
}
