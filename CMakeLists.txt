project(game)
cmake_minimum_required(VERSION 3.0)

add_subdirectory(engine)

include_directories(
		engine/header
		engine/SDL/include
		engine/lua/src
)


add_executable(game main.cpp)

target_link_libraries(game engine)