#include "point.h"

template<typename T>
point::point(T x, T y) : x_(x), y_(y) { }

bool point::operator==(const point& p1, const point& p2) const
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}

template<typename T>
T point::x() const { return x_; }

template<typename T>
T point::y() const { return y_; }
