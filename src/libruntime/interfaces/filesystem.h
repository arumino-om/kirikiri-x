#pragma once
#include <filesystem>
#include <fstream>

namespace LibRuntime::Interfaces {
    /**
     * ファイルシステムへアクセスするためのインターフェース
     */
    class IFileSystem {
    public:
        virtual std::wstring get_current_directory() = 0;
        virtual void set_current_directory(const std::wstring &path) = 0;

        virtual std::wfstream open_file(const std::wstring &path) = 0;
    };

    /**
     * IFileSystem のフォールバック実装
     */
    class FileSystemFallbackImpl : public IFileSystem {
    public:
        std::wstring get_current_directory() override {
            return std::filesystem::current_path().wstring();
        }

        void set_current_directory(const std::wstring &path) override {
            std::filesystem::current_path(path);
        }

        std::wfstream open_file(const std::wstring &path) override {
            return std::wfstream(path);
        }
    };
}

