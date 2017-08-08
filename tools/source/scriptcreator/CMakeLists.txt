project(scriptcreator)
cmake_minimum_required(VERSION 3.0)

add_executable(scriptcreator main.cpp)

set_target_properties(scriptcreator
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)