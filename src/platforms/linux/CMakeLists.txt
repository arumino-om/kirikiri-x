
add_library(linux_impl STATIC
        sysfunc_impl.cpp
        sysfunc_impl.h
        system_ui_impl.cc
        system_ui_impl.h
)

target_include_directories(linux_impl PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(LIBADW REQUIRED IMPORTED_TARGET libadwaita-1)

target_link_libraries(linux_impl PUBLIC PkgConfig::LIBADW runtime)