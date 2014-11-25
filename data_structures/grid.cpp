#include "grid.h"

template<typename T>
grid::grid(unsigned int width, unsigned int height)
        : width_(width), height_(height)
{
    std::vector::resize(width_ * height);
}

unsigned int grid::width() const { return width_; }

unsigned int grid::height() const { return height_; }

template<typename T>
T grid::at(unsigned int x, unsigned int y) const
{
    auto item = y * width_ + x;
    return std::vector::at(item);
}
