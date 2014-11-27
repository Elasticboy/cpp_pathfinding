#include <vector>
#include <stdexcept>

#pragma once

/**
* This class represents a two dimensional matrix.
* The data are stored in a nested std::vector<T>.
*/
template<typename T>
class grid : public std::vector<T> {

public:
    grid(const unsigned int& width, const unsigned int& height)
            : std::vector<T>(width * height), width_(width), height_(height)
    {
        std::vector<T>::resize(width_ * height);
    }

    /** @return The width of the grid */
    unsigned int width() const { return width_; }

    /** @return The height of the grid */
    unsigned int height() const { return height_; }

    /**
    * @Param x position of the item
    * @Param y position of the item
    * @return TA reference to the item at the given position
    * The parameter are first checked that they are in the range of the grid.
    * The function throws out_of_range if the check fails.
    */
    T& at(unsigned int x, unsigned int y)
    {
        // Check out of bound error
        if (x < 0 || x >= width_) {
            throw std::out_of_range("x is out of the grid bounds (" + std::to_string(width_) + "x" + std::to_string(height_) + ").");
        }
        if (y < 0 || y >= height_) {
            throw std::out_of_range("y is out of the grid bounds (" + std::to_string(width_) + "x" + std::to_string(height_) + ").");
        }
        auto itemId = y * width_ + x;
        return std::vector<T>::at(itemId);
    }

private:

    /** Width of the grid */
    unsigned int width_;

    /** Height of the grid */
    unsigned int height_;
};
