#pragma once 

#include <cmath>
#include <iostream>

#include "Point.h"

class Figure {
protected:
    Point* vertex_list;
    int vertex_count;
    void setVertices(int count, const Point* vertices = nullptr);
   
public:
    Figure();
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    virtual ~Figure();

    virtual void read(std::istream& input) = 0;
    virtual void print(std::ostream& output) const = 0;
    virtual double area() const = 0;
    virtual Figure* clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    
    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;

    Point center() const;
    
    Point& operator[](int index);
    const Point& operator[](int index) const;
    int getVertexCount() const { return vertex_count; }
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);
};