project(lua)
cmake_minimum_required(VERSION 3.0)

file(GLOB LUA_HEADER_H ${CMAKE_CURRENT_SOURCE_DIR}/lua/src/*.h)
file(GLOB LUA_HEADER_HPP ${CMAKE_CURRENT_SOURCE_DIR}/lua/src/*.hpp)

file(GLOB LUA_SOURCE_C ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
file(GLOB LUA_SOURCE_CPP ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_library(lua ${LUA_HEADER_H} ${LUA_HEADER_HPP} ${LUA_SOURCE_C})