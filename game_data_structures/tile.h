#include "../data_structures/point.h"

#pragma once

class tile : public point<unsigned int> {

public:

    tile(unsigned int x, unsigned int y);
    tile(unsigned int x, unsigned int y, bool buildable);

    bool isBuildable();

private:

    /** True if the tile is walkable */
    bool walkable_;

    /** True if the tile is buildable */
    bool buildable_;
};
