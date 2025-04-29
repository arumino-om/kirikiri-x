# ============= KIRIKIRI X =============
# Kirikiri X is a cross-platform game engine based on Kirikiri Z
# ======================================

cmake_minimum_required(VERSION 3.21)
project(krkrx LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === 外部ライブラリをインポート ===
include(FetchContent)
FetchContent_Declare(
        googletest
        DOWNLOAD_EXTRACT_TIMESTAMP ON
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_Declare(
        sdl2
        DOWNLOAD_EXTRACT_TIMESTAMP ON
        URL https://github.com/libsdl-org/SDL/archive/refs/tags/release-2.32.2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(sdl2)
add_subdirectory(src/third_party/oniguruma EXCLUDE_FROM_ALL)

# === 吉里吉里X本体 ===
add_subdirectory(src/runtime EXCLUDE_FROM_ALL)

if(WIN32)
    # Windows 向けビルド
    add_compile_definitions(UNICODE)
    if (MSVC)
        add_compile_options("/source-charset:utf-8")
    endif()
    add_subdirectory(src/platforms/windows EXCLUDE_FROM_ALL)
    set(PLATFORM_IMPL_TARGET win32_impl)
    set(PLATFORM_ENTRY_POINT_FILE src/platforms/windows/main.cc)

elseif(UNIX)
    # UNIX, Linux 向けビルド
    add_subdirectory(src/platforms/linux EXCLUDE_FROM_ALL)
    set(PLATFORM_IMPL_TARGET linux_impl)
    set(PLATFORM_ENTRY_POINT_FILE src/platforms/linux/main.cc)

else()
    message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM_NAME}")
endif()

add_executable(${PROJECT_NAME} ${PLATFORM_ENTRY_POINT_FILE})
target_link_libraries(${PROJECT_NAME} PRIVATE
        runtime
        ${PLATFORM_IMPL_TARGET}
)

# === テスト ===
# src/tests/CMakeLists.txt にテスト用の定義が記載されている
add_subdirectory(src/tests)