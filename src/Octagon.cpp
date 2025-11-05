#include "Octagon.h"

#include <iostream>

#include "Point.h"

Octagon::Octagon() {
    setVertices(8);
}

Octagon::Octagon(const Octagon& other) : Figure(other) {}

Octagon::Octagon(Octagon&& other) noexcept : Figure(std::move(other)) {}

Octagon& Octagon::operator=(const Octagon& other) {
    Figure::operator=(other);
    return *this;
}

Octagon& Octagon::operator=(Octagon&& other) noexcept {
    Figure::operator=(std::move(other));
    return *this;
}

void Octagon::read(std::istream& input) {
    std::cout << "Введите 8 точек восьмиугольника:\n";
    for (int idx = 0; idx < 8; idx++) {
        Point vertex; 
        std::cout << "Точка " << (idx + 1) << ": "; 
        input >> vertex.coord_x >> vertex.coord_y;
        (*this)[idx] = vertex;
    }
}

void Octagon::print(std::ostream& output) const {
    output << "Восьмиугольник: площадь=" << area() << " центр=(" 
           << center().coord_x << "," << center().coord_y << ")";
}

double Octagon::area() const {
    if (getVertexCount() != 8) return 0;
   
    double area_sum = 0;
    for (int i = 0; i < 8; ++i) {
        int j = (i + 1) % 8;
        area_sum += (*this)[i].coord_x * (*this)[j].coord_y - 
                   (*this)[j].coord_x * (*this)[i].coord_y;
    }
    return std::abs(area_sum) / 2.0;
}

Octagon* Octagon::clone() const {
    return new Octagon(*this);
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* octagon_ptr = dynamic_cast<const Octagon*>(&other);
    if (!octagon_ptr || getVertexCount() != octagon_ptr->getVertexCount()) {
        return false;
    }
    
    for (int i = 0; i < getVertexCount(); ++i) {
        if (!((*this)[i] == (*octagon_ptr)[i])) {
            return false;
        }
    }
    return true;
}