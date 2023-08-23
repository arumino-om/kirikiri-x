#pragma once
#include "windows.h"
#include "interfaces/console.h"

class WindowsConsole: public LibRuntime::Interfaces::IConsole {
public:
    void write(const tjs_char *text) override;
    void error(const tjs_char *text) override;
    size_t readline(const tjs_char *&result) override;
private:
    static int convert_wide2mb(const wchar_t *wtext, char *&mbtext, UINT code_page);
    void output(const tjs_char *text, std::ostream *out_stream);
};
