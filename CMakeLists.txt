cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

project(BattleShip C CXX ASM)

add_executable(${CMAKE_PROJECT_NAME} src/BattleShip.cpp
    src/Board.cpp
    src/Game.cpp
    src/Input.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    include
)