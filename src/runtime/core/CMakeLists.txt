cmake_minimum_required(VERSION 3.13)
if (MSVC)
    #        add_compile_options("/utf-8")
    add_compile_options("/std:c++20")
    add_compile_options("/source-charset:utf-8")
endif()

add_library(libruntime STATIC
        interfaces/filesystem.h
        interfaces/console.h
        native_classes/minimal.cc
        native_classes/minimal.h
        libruntime.cc
        libruntime.h
        script_manager.cc
        script_manager.h
        messages.cc
        messages.h
        native_classes/system.cc
        native_classes/system.h
        event_manager.cc
        event_manager.h
        interfaces/sysfunc.h
        native_classes/window.cc
        native_classes/window.h
        native_instances/window_instance.cc
        native_instances/window_instance.h
        window_manager.cc
        window_manager.h
        native_instances/layer_instance.cc
        native_instances/layer_instance.h
        native_classes/layer.cc
        native_classes/layer.h
        rendering/layer_tree.cc
        rendering/layer_tree.h
        native_classes/rect.cc
        native_classes/rect.h
        native_instances/rect_instance.cc
        native_instances/rect_instance.h
        types/rect.h)

target_include_directories(libruntime PUBLIC ../tjs2)
target_include_directories(libruntime PUBLIC ../libsdl2/include)

target_link_libraries(libruntime libtjs2)