#pragma once

/**
* Simple data structure representing cartesian coordinates.
* A point p1 is equal to a point p2 if p1.x == p2.x and p1.y == p2.y.
*/
template<typename T>
class point {

public:
    point(T x, T y) : x_(x), y_(y) { }

    bool operator==(const point& compared) const
    {
        return x_ == compared.x() && y_ == compared.y();
    }

    T x() const { return x_; }
    T y() const { return y_; }

protected:
    T x_;
    T y_;
};