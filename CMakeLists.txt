# ======== KIRIKIRI X ========
# Kirikiri X is a cross-platform game engine based on Kirikiri Z
# ============================

cmake_minimum_required(VERSION 3.21)
project(krkrx LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/third_party/oniguruma EXCLUDE_FROM_ALL)
add_subdirectory(src/third_party/sdl EXCLUDE_FROM_ALL)
add_subdirectory(src/runtime EXCLUDE_FROM_ALL)

if(WIN32)
    add_compile_definitions(UNICODE)
    if (MSVC)
        add_compile_options("/source-charset:utf-8")
    endif()
    # Windows向けにビルドする場合
    add_subdirectory(src/platforms/windows EXCLUDE_FROM_ALL)
    # platform/windows/CMakeLists.txt で platform_impl というターゲットが定義されると想定
    set(PLATFORM_IMPL_TARGET win32_impl)
    set(PLATFORM_ENTRY_POINT_FILE src/platforms/windows/main.cc)

elseif(UNIX)
    # Linux, macOS, BSDなどのUnix系システム向けにビルドする場合
    add_subdirectory(src/platforms/linux EXCLUDE_FROM_ALL)
    set(PLATFORM_IMPL_TARGET linux_impl)
    set(PLATFORM_ENTRY_POINT_FILE src/platforms/linux/main.cc)

else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

add_executable(${PROJECT_NAME} ${PLATFORM_ENTRY_POINT_FILE})

# 実行可能ファイルに依存ライブラリをリンク
# engine_core ライブラリと、選択されたプラットフォーム実装ライブラリをリンクします。
target_link_libraries(${PROJECT_NAME} PRIVATE
        runtime
        ${PLATFORM_IMPL_TARGET}
)
