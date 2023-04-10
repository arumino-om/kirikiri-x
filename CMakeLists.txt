cmake_minimum_required(VERSION 3.13)
add_definitions( -std=c++11 )
project(kirikiri_s LANGUAGES C CXX)

add_subdirectory(src/liboniguruma)
include_directories(src/liboniguruma/src src/libtjs2)
add_subdirectory(src/libtjs2)

add_executable(krkrs src/libruntime/main.cc)
target_link_libraries(krkrs PUBLIC onig libtjs2)