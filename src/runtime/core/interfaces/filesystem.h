#pragma once
#include "tjs.h"
#include "tjsTypes.h"

namespace LibRuntime::Interfaces {
    /**
     * ファイルシステムへアクセスするためのインターフェース
     */
    class IFileSystem {
    public:
        // カレントディレクトリ
        virtual size_t get_current_directory(tjs_char *result) = 0;
        virtual bool set_current_directory(const tjs_char *path) = 0;

        // ファイル開閉
        virtual tTJSBinaryStream *open(const tjs_char *path, tjs_uint32 flags) = 0;

        // 存在確認
        virtual bool file_exists(const tjs_char *path) = 0;
        virtual bool directory_exists(const tjs_char *path) = 0;

        // ファイルシステム情報関連
        virtual tjs_int get_maxpath_length() = 0;
        virtual bool get_home_directory(tjs_string &result) = 0;
        virtual bool get_appdata_directory(tjs_string &result) = 0;
        virtual bool get_savedata_directory(tjs_string &result) = 0;

        // ユーティリティ
        virtual bool path_combine(const tjs_string &path1, const tjs_string &path2, tjs_string &result) = 0;
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

        bool get_home_directory(tjs_string &result) override {
            return false;
        }

        bool get_appdata_directory(tjs_string &result) override {
            return false;
        }

        bool get_savedata_directory(tjs_string &result) override {
            return false;
        }

        bool path_combine(const tjs_string &path1, const tjs_string &path2, tjs_string &result) override {
            return false;
        }
    };
}

