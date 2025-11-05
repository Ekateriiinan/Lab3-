#include "Square.h"

#include <iostream>

#include "Point.h"

Square::Square() {
    setVertices(4);
}

Square::Square(const Square& other) : Figure(other) {}

Square::Square(Square&& other) noexcept : Figure(std::move(other)) {}

Square& Square::operator=(const Square& other) {
    Figure::operator=(other);
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    Figure::operator=(std::move(other));
    return *this;
}

void Square::read(std::istream& input) {
    std::cout << "Введите 4 точки квадрата:\n";
    for (int idx = 0; idx < 4; idx++) {
        Point vertex; 
        std::cout << "Точка " << (idx + 1) << ": "; 
        input >> vertex.coord_x >> vertex.coord_y;
        (*this)[idx] = vertex;
    }
}

void Square::print(std::ostream& output) const {
    output << "Квадрат: площадь=" << area() << " центр=(" 
           << center().coord_x << "," << center().coord_y << ")";
}

double Square::area() const {
    if (getVertexCount() != 4) return 0;
    
    const Point& p1 = (*this)[0];
    const Point& p2 = (*this)[1];
    const Point& p3 = (*this)[2];
    const Point& p4 = (*this)[3];
    
    double area_sum = 0;
    for (int i = 0; i < 4; ++i) {
        int j = (i + 1) % 4;
        area_sum += (*this)[i].coord_x * (*this)[j].coord_y - 
                   (*this)[j].coord_x * (*this)[i].coord_y;
    }
    return std::abs(area_sum) / 2.0;
}

Square* Square::clone() const {
    return new Square(*this);
}

bool Square::operator==(const Figure& other) const {
    const Square* square_ptr = dynamic_cast<const Square*>(&other);
    if (!square_ptr || getVertexCount() != square_ptr->getVertexCount()) {
        return false;
    }
    
    for (int i = 0; i < getVertexCount(); ++i) {
        if (!((*this)[i] == (*square_ptr)[i])) {
            return false;
        }
    }
    return true;
}