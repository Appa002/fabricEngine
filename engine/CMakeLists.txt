project(engine)
cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/header)

set(HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/header/engine.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/behavior.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/singleton.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/types.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/gameobject.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/map.hpp

	${CMAKE_CURRENT_SOURCE_DIR}/game/scripts/header
)

set(SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/behavior.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/engine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/gameobject.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/map.cpp

	${CMAKE_CURRENT_SOURCE_DIR}/game/game.cpp
)

add_subdirectory(game/scripts/source)

add_executable(engine main.cpp ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(engine game)
