#include "Triangle.h"

#include "Point.h"

Triangle::Triangle() {
    setVertices(3);
}

Triangle::Triangle(const Triangle& other) : Figure(other) {}

Triangle::Triangle(Triangle&& other) noexcept : Figure(std::move(other)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    Figure::operator=(other);
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    Figure::operator=(std::move(other));
    return *this;
}

void Triangle::read(std::istream& input) {
    std::cout << "Введите 3 точки треугольника:\n";
    for (int idx = 0; idx < 3; idx++) {
        Point vertex; 
        std::cout << "Точка " << (idx + 1) << ": "; 
        input >> vertex.coord_x >> vertex.coord_y;
        (*this)[idx] = vertex;
    }
}

void Triangle::print(std::ostream& output) const {
    output << "Треугольник: площадь=" << area() << " центр=(" 
           << center().coord_x << "," << center().coord_y << ")";
}

double Triangle::area() const {
    if (getVertexCount() != 3) return 0;
    
    const Point& p1 = (*this)[0];
    const Point& p2 = (*this)[1];
    const Point& p3 = (*this)[2];
    
    return std::abs((p1.coord_x*(p2.coord_y - p3.coord_y) + 
                     p2.coord_x*(p3.coord_y - p1.coord_y) + 
                     p3.coord_x*(p1.coord_y - p2.coord_y)) / 2.0);
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* triangle_ptr = dynamic_cast<const Triangle*>(&other);
    if (!triangle_ptr || getVertexCount() != triangle_ptr->getVertexCount()) {
        return false;
    }
    
    for (int i = 0; i < getVertexCount(); ++i) {
        if (!((*this)[i] == (*triangle_ptr)[i])) {
            return false;
        }
    }
    return true;
}