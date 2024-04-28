#pragma once
#include "tjs.h"
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

        virtual tTJSBinaryStream *open(const tjs_char *path, tjs_uint32 flags) = 0;

        virtual bool file_exists(const tjs_char *path) = 0;
        virtual bool directory_exists(const tjs_char *path) = 0;

        virtual tjs_int get_maxpath_length() = 0;

        virtual bool path_combine(const tjs_char *path1, const tjs_char *path2, tjs_char *out) = 0;
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

        bool file_exists(const tjs_char *path) override {
            return false;
        }

        bool directory_exists(const tjs_char *path) override {
            return false;
        }

        tTJSBinaryStream *open(const tjs_char *path, tjs_uint32 flags) override {
            return nullptr;
        };

        tjs_int get_maxpath_length() override {
            return 260;
        };

        bool path_combine(const tjs_char *path1, const tjs_char *path2, tjs_char *out) override {
            return false;
        }
    };
}

