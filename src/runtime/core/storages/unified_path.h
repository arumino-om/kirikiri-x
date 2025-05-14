#pragma once
#include <tjs.h>

namespace LibRuntime::Storages {
    class UnifiedPath {
    public:
        UnifiedPath();
        UnifiedPath(const ttstr &media, const ttstr &domain, const ttstr &path);

        [[nodiscard]] ttstr get_media() const;
        [[nodiscard]] ttstr get_domain() const;
        [[nodiscard]] ttstr get_path() const;
        [[nodiscard]] UnifiedPath get_parent_path() const;

        void set_media(const ttstr &media);
        void set_domain(const ttstr &domain);
        void set_path(const ttstr &path);

        [[nodiscard]] ttstr get_fullpath() const;

    private:
        ttstr media;
        ttstr domain;
        ttstr path;
    };

}
