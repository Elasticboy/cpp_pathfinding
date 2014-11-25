#include <iostream>
#include "pathfinding/shortest_path.h"


int main()
{

    std::cout << "Starting path finding algorythm!" << std::endl;

    // Build the grid
    const int GRID_WIDTH = 10;
    const int GRID_HEIGHT = 10;
    playground grid = playground(GRID_WIDTH, GRID_HEIGHT);

    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            grid[y][x] = tile(x, y, true);
        }
    }

    shortest_path::compute_shortest_path(point(1, 1), point(5, 5), grid);
    return 0;
}

