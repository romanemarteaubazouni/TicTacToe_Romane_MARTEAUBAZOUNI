cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Bibliothèque Player
add_library(player STATIC
    src/player.cpp
)

# Exécutable principal
add_executable(main
    src/main.cpp
)

target_link_libraries(main player)
