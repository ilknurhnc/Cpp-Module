#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(float x, float y) : x(x), y(y){}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}