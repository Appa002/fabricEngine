project(fabricEngine)
cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

add_subdirectory (src)

add_executable(fabricEngine main.cpp)

target_link_libraries(fabricEngine behavior)
target_link_libraries(fabricEngine engine)
