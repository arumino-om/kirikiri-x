cmake_minimum_required(VERSION 3.13)
add_definitions( -std=c++11 )
project(kirikiri_s LANGUAGES C CXX)

include_directories(src/liboniguruma/src src/libtjs2 src/libruntime)

add_subdirectory(src/liboniguruma)
add_subdirectory(src/libtjs2)
add_subdirectory(src/libruntime)

add_executable(krkrs src/windows/main.cc)
target_link_libraries(krkrs PUBLIC onig libtjs2 libruntime)