// Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const x;
    Fixed const y;

public:
    Point();                              // Default ctor
    Point(float x, float y);              // Parametrized ctor
    Point(const Point& obj);            // Copy ctor
    Point& operator=(const Point& obj); // Copy assignment
    ~Point();                             // Destructor

    Fixed getX() const;
    Fixed getY() const;
};

#endif
