project(fabricEngine)
cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

add_subdirectory (src)

set(HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/header/engine.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/behavior.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/singleton.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/types.hpp)

add_executable(fabricEngine main.cpp ${HEADER_FILES})

target_link_libraries(fabricEngine behavior)
target_link_libraries(fabricEngine engine)
