#pragma once

#include "Figure.h"

class Square : public Figure {
public:
    Square();
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    
    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    double area() const override;
    Square* clone() const override;
    bool operator==(const Figure& other) const override;
};