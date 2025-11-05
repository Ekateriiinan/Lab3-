#pragma once

#include "Figure.h"

class Octagon : public Figure {
public:
    Octagon();
    Octagon(const Octagon& other);
    Octagon(Octagon&& other) noexcept;
    Octagon& operator=(const Octagon& other);
    Octagon& operator=(Octagon&& other) noexcept;
    
    void read(std::istream& input) override;
    void print(std::ostream& output) const override;
    double area() const override;
    Octagon* clone() const override;
    bool operator==(const Figure& other) const override;
};