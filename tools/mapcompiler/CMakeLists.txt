project(mapcompiler)
cmake_minimum_required(VERSION 3.0)

add_executable(mapcompiler main.cpp)

set_target_properties(mapcompiler
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)