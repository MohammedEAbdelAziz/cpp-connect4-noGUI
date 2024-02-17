cmake_minimum_required(VERSION 3.10)

project(Connect4)

# Add all your source files
set(SOURCES
    ./src/4_in_a_row_app.cpp
    ./src/FourInRowBoard.cpp
    ./src/FourInRowPlayers.cpp
    ./src/FourInRowGameManager.cpp
    ./src/drdeclare.cpp
    ./main.cpp
)

# Add your header file directory
include_directories(${CMAKE_SOURCE_DIR})

# Create the executable
add_executable(Connect4 ${SOURCES})