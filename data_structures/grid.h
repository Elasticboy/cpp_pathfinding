#include <vector>

#pragma once

/**
* This class represents a two dimensional matrix.
* The data are stored in a nested std::vector<T>.
*/
template<typename T>
class grid : public std::vector<T> {

public:
    grid(unsigned int width, unsigned int height);

    /** @return The width of the grid */
    unsigned int width() const;

    /** @return The height of the grid */
    unsigned int height() const;

    /**
    * @Param x position of the item
    * @Param y position of the item
    * @return The item at the given position
    * The parameter are first checked that they are in the range of the grid.
    * The function throws out_of_range if the check fails.
    */
    T at(unsigned int x, unsigned int y) const;

private:

    /** Width of the grid */
    unsigned int width_;

    /** Height of the grid */
    unsigned int height_;
};
