#include <iostream>
#include "data_structures/grid.h"
#include "pathfinding/shortest_path.h"

int main()
{
    std::cout << "Starting path finding algorythm!" << std::endl;

    // Build the grid
    std::cout << "Building the grid" << std::endl;
    const unsigned int GRID_WIDTH = 10;
    const unsigned int GRID_HEIGHT = 10;
    auto playground = grid<tile*>(GRID_WIDTH, GRID_HEIGHT);

    for (unsigned int y = 0; y < GRID_HEIGHT; y++) {
        for (unsigned int x = 0; x < GRID_WIDTH; x++) {
            playground.push_back(new tile(x, y, true));
        }
    }

    try {
        shortest_path::compute_shortest_path(1, 1, 5, 5, playground);
    } catch (const std::exception& e) {
        std::cout << "An error occurred:" << e.what() << std::endl;
    }

    std::cout << "Algorythm completed" << std::endl;

    return 0;
}

