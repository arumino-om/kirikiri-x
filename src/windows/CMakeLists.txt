cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} WINDOWS_SOURCES)

add_executable(krkrx_win ${WINDOWS_SOURCES})
add_link_options(krkrx_win -lshlwapi)
target_link_libraries(krkrx_win PUBLIC onig libtjs2 libruntime)