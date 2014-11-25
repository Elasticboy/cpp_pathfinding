#pragma once

/**
* Simple data structure representing cartesian coordinates.
* A point p1 is equal to a point p2 if p1.x == p2.x and p1.y == p2.y.
*/
template<typename T>
class point<T> {

public:
    point(T x, T y);
    bool operator ==(const point& p1, const point& p2) const;

    T x() const;
    T y() const;

protected:
    T x_;
    T y_;
};