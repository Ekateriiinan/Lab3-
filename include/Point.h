#pragma once

class Point {
public:
    double coord_x, coord_y;
    Point(double x = 0, double y = 0) : coord_x(x), coord_y(y) {}
    bool operator==(const Point& other) const { 
        return coord_x == other.coord_x && coord_y == other.coord_y; 
    }
};