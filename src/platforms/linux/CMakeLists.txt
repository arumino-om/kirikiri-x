
set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/mnt/home/p220039/vroot/usr/lib/x86_64-linux-gnu/pkgconfig")

add_library(linux_impl STATIC
        sysfunc_impl.cpp
        sysfunc_impl.h
        system_ui_impl.cc
        system_ui_impl.h
        environment_impl.cc
        environment_impl.h
)

target_include_directories(linux_impl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(LIBADW REQUIRED IMPORTED_TARGET gtk+-3.0)

target_link_libraries(linux_impl PUBLIC PkgConfig::LIBADW runtime)