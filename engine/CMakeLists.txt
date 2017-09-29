project(engine)
cmake_minimum_required(VERSION 3.0)

file(GLOB LUA_HEADER_H ${CMAKE_CURRENT_SOURCE_DIR}/lua/src/*h)
file(GLOB LUA_HEADER_HPP ${CMAKE_CURRENT_SOURCE_DIR}/lua/src/*hpp)

set(HEADER_FILES 
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/engine.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/singleton.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/types.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/gameobject.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/map.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/logfile.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/shaderObj.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/shaderProgramObj.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/vertex_buffer_object.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/vertex_attribute_object.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/unit_framework.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/tests.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/objectUtils.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/transform.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/gameobjectHandler.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/mesh.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/error_handler.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/dataCore.hpp

)

set(SOURCE_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/engine.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/gameobject.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/map.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/logfile.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/shaderObj.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/shaderProgramObj.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/vertex_buffer_object.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/vertex_attribute_object.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/unit_framework.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/tests.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/transform.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/gameobjectHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/mesh.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/error_handler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/dataCore.cpp
)


add_subdirectory(lua)

add_library(engine ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(engine lua)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/SDL2.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/glew32.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/glew32s.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/SDL2main.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/SDL2test.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/OpenGL32.lib)