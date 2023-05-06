#include "tjs.h"
#pragma once

class GCOT : public iTJSConsoleOutput {
public:
    void ExceptionPrint(const tjs_char *message) override;
    void Print(const tjs_char* message) override;
};

int start();