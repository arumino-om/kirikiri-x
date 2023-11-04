cmake_minimum_required(VERSION 3.13)
project(kirikiri_x LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(src/liboniguruma/src src/libtjs2 src/libruntime)

add_subdirectory(src/liboniguruma)
add_subdirectory(src/libsdl2 EXCLUDE_FROM_ALL)
add_subdirectory(src/libtjs2)
add_subdirectory(src/libruntime)

add_definitions(-DDEBUG)

if(UNIX)
    add_executable(krkrx src/linux/main.cc)
elseif(WIN32)
    # UTF-8を明記
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

    add_executable(krkrx WIN32 src/windows/main.cc src/windows/filesystem_impl.cc src/windows/filesystem_impl.h src/windows/console_impl.cc src/windows/console_impl.h
            src/windows/systemgui_impl.cc
            src/windows/systemgui_impl.h
            src/windows/windows_utils.cc
            src/windows/windows_utils.h)
endif()

if(TARGET SDL2::SDL2main)
    target_link_libraries(krkrx PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(krkrx PUBLIC SDL2::SDL2)

target_link_libraries(krkrx PUBLIC onig libtjs2 libruntime)
