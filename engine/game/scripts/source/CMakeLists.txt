include_directories(../header)

file (GLOB GAME_SOURCE "*.cpp")

file (GLOB HEADER_SOURCE "../header/*.hpp")

add_library(game ${GAME_SOURCE} ${HEADER_SOURCE})
