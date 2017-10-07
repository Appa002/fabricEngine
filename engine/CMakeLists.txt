project(engine)
cmake_minimum_required(VERSION 3.0)

file(GLOB LUA_HEADER_H ${CMAKE_CURRENT_SOURCE_DIR}/lua/src/*.h)
file(GLOB LUA_HEADER_HPP ${CMAKE_CURRENT_SOURCE_DIR}/lua/src/*.hpp)

file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/header/fabric/*.hpp)
file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/fabric/*.cpp)

add_subdirectory(lua)

add_library(engine ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(engine lua)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/SDL2.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/glew32.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/glew32s.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/SDL2main.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/SDL2test.lib)
target_link_libraries(engine ${CMAKE_CURRENT_SOURCE_DIR}/SDL/lib/x86/OpenGL32.lib)