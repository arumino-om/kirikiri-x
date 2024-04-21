#pragma once
#include "tjsTypes.h"
#include <fstream>

namespace LibRuntime::Interfaces {
    /**
     * ファイルシステムへアクセスするためのインターフェース
     */
    class IFileSystem {
    public:
        virtual size_t get_current_directory(tjs_char *result) = 0;
        virtual bool set_current_directory(const tjs_char *path) = 0;

        virtual std::fstream get_file(const tjs_char *path) = 0;

        virtual int get_maxpath_length() = 0;
    };

    /**
     * IFileSystem のフォールバック実装
     */
    class FileSystemFallbackImpl : public IFileSystem {
    public:
        size_t get_current_directory(tjs_char *result) override {
            return -1;
        };
        bool set_current_directory(const tjs_char *path) override {
            return false;
        };

        std::fstream get_file(const tjs_char *path) override {
            return nullptr;
        };

        int get_maxpath_length() override {
            return 256;
        };
    };
}

