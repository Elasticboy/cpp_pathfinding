#include "tile.h"

tile::tile(unsigned int x, unsigned int y)
        : point(x, y), buildable_(true) { }

tile::tile(unsigned int x, unsigned int y, bool buildable)
        : point(x, y), buildable_(buildable) { }

bool tile::isBuildable() { return buildable_; }
