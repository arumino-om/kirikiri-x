cmake_minimum_required(VERSION 3.13)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} LINUX_SOURCES)

add_executable(krkrs_linux ${LINUX_SOURCES})
target_link_libraries(krkrs_linux PUBLIC onig libtjs2 libruntime)