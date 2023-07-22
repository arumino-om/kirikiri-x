#pragma once
#include "windows.h"
#include "interfaces/console.h"

class WindowsConsole: public LibRuntime::IConsole {
public:
    void write(const tjs_char *text) override;
    void error(const tjs_char *text) override;
private:
    static int convert_wide2mb(const wchar_t *wtext, char *&mbtext, UINT code_page);
    void output(const tjs_char *text, std::ostream *out_stream);
};
