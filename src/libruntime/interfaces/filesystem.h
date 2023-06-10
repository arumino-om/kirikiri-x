#pragma once
#include <fstream>

namespace LibRuntime {
    /**
     * ファイルシステムへアクセスするためのインターフェース
     */
    class IFileSystem {
    public:
        virtual bool get_current_directory(wchar_t *result, size_t result_size) = 0;
        virtual bool set_current_directory(const wchar_t *path) = 0;

        virtual std::wfstream get_file(const wchar_t *path) = 0;

        virtual int get_maxpath_length() = 0;
    };

    /**
     * IFileSystem のフォールバック実装
     */
    class FileSystemFallbackImpl: public IFileSystem {
    public:
        bool get_current_directory(wchar_t *result, size_t result_size) override {
            return false;
        };
        bool set_current_directory(const wchar_t *path) override {
            return false;
        };

        std::wfstream get_file(const wchar_t *path) override {
            return nullptr;
        };

        int get_maxpath_length() override {
            return 256;
        };
    };
}

