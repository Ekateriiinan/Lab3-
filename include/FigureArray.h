#pragma once

#include "Figure.h"


class FigureArray {
private:
    Figure** data;
    int size_;
    int capacity_;
    
    void resize(int new_capacity);
    
public:
    FigureArray();
    ~FigureArray();
    
    void addFigure(Figure* fig);
    void removeFigure(int index);
    double totalArea() const;
    int size() const { return size_; }
    
    Figure* operator[](int index);
    const Figure* operator[](int index) const;
    
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
};