cmake_minimum_required(VERSION 3.13)

add_library(libruntime STATIC
        interfaces/filesystem.h
        interfaces/console.h
        native_objects/minimal.cc
        native_objects/minimal.h
        libruntime.cc
        libruntime.h
        script_manager.cc
        script_manager.h
        messages.cc
        messages.h
        graphics.cc
        graphics.h
        native_objects/system.cc
        native_objects/system.h)

target_include_directories(libruntime PUBLIC ../libtjs2)
target_include_directories(libruntime PUBLIC ../libsdl2/include)

target_link_libraries(libruntime libtjs2)