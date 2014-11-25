cmake_minimum_required(VERSION 2.8.4)
project(game_lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    pathfinding/node.cpp
    pathfinding/node.h
    pathfinding/shortest_path.cpp
    pathfinding/shortest_path.h
    game_data_structures/tile.cpp
    game_data_structures/tile.h
    data_structures/point.cpp
    data_structures/point.h
    data_structures/grid.cpp
    data_structures/grid.h
)
add_executable(game_lib ${SOURCE_FILES})