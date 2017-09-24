project(game)
cmake_minimum_required(VERSION 3.0)

include_directories(
		engine/header
		engine/SDL/include
		engine/lua/src
)

add_subdirectory(engine)
add_subdirectory(gameobjects/a)



add_executable(game main.cpp)

target_link_libraries(game engine)
target_link_libraries(game gameobject)