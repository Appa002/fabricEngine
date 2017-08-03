project(engine)
cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

file (GLOB SDL_SOURCE 
	"${CMAKE_CURRENT_SOURCE_DIR}/SDL/include/*.h")


LINK_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/win32)

set(HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/header/engine.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/behavior.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/singleton.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/types.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/gameobject.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/map.hpp

	${CMAKE_CURRENT_SOURCE_DIR}/game/scripts/header
	${CMAKE_CURRENT_SOURCE_DIR}/game/resources/maps/badwater.hpp
)

set(SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/behavior.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/engine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameobject.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/map.cpp
	
	${CMAKE_CURRENT_SOURCE_DIR}/game/game.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/game/resources/maps/badwater.cpp
)

add_subdirectory(game/scripts/source)

add_executable(engine main.cpp ${HEADER_FILES} ${SDL_SOURCE} ${SOURCE_FILES})
target_link_libraries(engine game)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/win32/SDL2.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/win32/SDL2main.lib)