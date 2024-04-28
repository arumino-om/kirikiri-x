cmake_minimum_required(VERSION 3.13)
project(kirikiri_x LANGUAGES C CXX)

add_definitions( -std=c++20 )
add_definitions(-DDEBUG)

include_directories(src/liboniguruma/src src/libtjs2 src/libruntime)

add_subdirectory(src/liboniguruma)
add_subdirectory(src/libsdl2 EXCLUDE_FROM_ALL)
add_subdirectory(src/libtjs2)
add_subdirectory(src/libruntime)

if (UNIX)
    add_executable(krkrx src/linux/main.cc)
elseif (WIN32)
    add_definitions(-DUNICODE)
    add_executable(krkrx WIN32 src/windows/main.cc src/windows/filesystem_impl.cc src/windows/filesystem_impl.h src/windows/console_impl.cc src/windows/console_impl.h
            src/windows/localfile_stream.cpp
            src/windows/localfile_stream.h)
    target_link_libraries(krkrx PUBLIC pathcch)
endif (UNIX)

if(TARGET SDL2::SDL2main)
    target_link_libraries(krkrx PRIVATE SDL2::SDL2main)
endif()
target_link_libraries(krkrx PUBLIC SDL2::SDL2)

target_link_libraries(krkrx PUBLIC onig libtjs2 libruntime)
