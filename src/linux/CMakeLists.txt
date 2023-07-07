cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LINUX_SOURCES)

add_executable(krkrx_linux ${LINUX_SOURCES})
target_link_libraries(krkrx_linux PUBLIC onig libtjs2 libruntime)