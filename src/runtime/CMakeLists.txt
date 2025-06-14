cmake_minimum_required(VERSION 3.13)

add_compile_definitions(UNICODE)
if (MSVC)
    add_compile_options("/std:c++20")
    add_compile_options("/source-charset:utf-8")
endif()

# TJS2のソースを取得（tjs2フォルダ内は変更が少ないため，この方法でいく）
FILE(GLOB_RECURSE TJS2_SOURCES  tjs2/*.cpp)
FILE(GLOB_RECURSE CORE_SOURCES  core/*.cc)
list(REMOVE_ITEM TJS2_SOURCES tjs2/tjsDateWordMap.cc)

message(STATUS "TJS2_SOURCES: ${TJS2_SOURCES}")
message(STATUS "CORE_SOURCES: ${CORE_SOURCES}")
# ライブラリ定義
add_library(runtime STATIC
        ${TJS2_SOURCES}
        ${CORE_SOURCES}
        core/interfaces/system_ui.h
)

target_include_directories(runtime
        PUBLIC
        core
        tjs2)

if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
    target_link_libraries(runtime PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(runtime PRIVATE onig SDL2::SDL2-static)