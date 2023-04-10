cmake_minimum_required(VERSION 3.13)
add_definitions( -std=c++11 )
project(kirikiri_s LANGUAGES C CXX)

include_directories(src/libtjs2 src/liboniguruma/src)

add_subdirectory(src/liboniguruma)
add_subdirectory(src/libtjs2)

add_executable(krkrs src/libruntime/main.cc)
target_link_libraries(krkrs onig libtjs2)