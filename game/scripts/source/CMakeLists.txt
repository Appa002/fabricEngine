include_directories(../header)

file (GLOB GAME_SOURCE "*.cpp")

add_library(game ${GAME_SOURCE})
