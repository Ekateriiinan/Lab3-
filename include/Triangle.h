#pragma once

#include "Figure.h"

class Triangle : public Figure {
public:
    Triangle();
    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
    
    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    double area() const override;
    Triangle* clone() const override;
    bool operator==(const Figure& other) const override;
};