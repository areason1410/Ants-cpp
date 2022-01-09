cmake_minimum_required(VERSION 3.16)

project(AntsAgain)

add_executable(antsagain
        src/
        src/main.cpp
        src/world/world.cpp
        src/world/colony.cpp
        src/world/grid.cpp
        src/world/cell.cpp
        src/entities/ant.cpp
        src/world/windowManager.cpp)

target_link_libraries(antsagain sfml-graphics sfml-window sfml-system)