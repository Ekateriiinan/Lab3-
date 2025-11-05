#include "Figure.h"

#include "Point.h"

Figure::Figure() : vertex_list(nullptr), vertex_count(0) {}

Figure::Figure(const Figure& other) : vertex_count(other.vertex_count) {
    vertex_list = new Point[vertex_count];
    for (int i = 0; i < vertex_count; ++i) {
        vertex_list[i] = other.vertex_list[i];
    }
}

Figure::Figure(Figure&& other) noexcept 
    : vertex_list(other.vertex_list), vertex_count(other.vertex_count) {
    other.vertex_list = nullptr;
    other.vertex_count = 0;
}

Figure::~Figure() {
    delete[] vertex_list;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        delete[] vertex_list;
        vertex_count = other.vertex_count;
        vertex_list = new Point[vertex_count];
        for (int i = 0; i < vertex_count; ++i) {
            vertex_list[i] = other.vertex_list[i];
        }
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        delete[] vertex_list;
        vertex_list = other.vertex_list;
        vertex_count = other.vertex_count;
        other.vertex_list = nullptr;
        other.vertex_count = 0;
    }
    return *this;
}

Point Figure::center() const {
    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < vertex_count; ++i) { 
        sum_x += vertex_list[i].coord_x; 
        sum_y += vertex_list[i].coord_y; 
    }
    return vertex_count == 0 ? Point() : Point(sum_x / vertex_count, sum_y / vertex_count);
}

Point& Figure::operator[](int index) {
    return vertex_list[index];
}

const Point& Figure::operator[](int index) const {
    return vertex_list[index];
}

void Figure::setVertices(int count, const Point* vertices) {
    delete[] vertex_list;
    vertex_count = count;
    vertex_list = new Point[count];
    if (vertices) {
        for (int i = 0; i < count; ++i) {
            vertex_list[i] = vertices[i];
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& fig) {
    fig.read(is);
    return is;
}
