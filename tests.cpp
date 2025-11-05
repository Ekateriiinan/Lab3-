#include <gtest/gtest.h>

#include <sstream>

#include "FigureArray.h"
#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"
#include "Point.h"

TEST(FigureTest, TriangleAreaAndCenter) {
    Triangle triangle;
    std::istringstream stream("0 0\n4 0\n2 3\n");
    triangle.read(stream);
    
    EXPECT_NEAR(triangle.area(), 6.0, 0.001);
    
    Point center = triangle.center();
    EXPECT_NEAR(center.coord_x, 2.0, 0.001);
    EXPECT_NEAR(center.coord_y, 1.0, 0.001);
}

TEST(FigureTest, SquareAreaAndCenter) {
    Square square;
    std::istringstream stream("0 0\n0 2\n2 2\n2 0\n");
    square.read(stream);
    
    EXPECT_NEAR(square.area(), 4.0, 0.001);
    
    Point center = square.center();
    EXPECT_NEAR(center.coord_x, 1.0, 0.001);
    EXPECT_NEAR(center.coord_y, 1.0, 0.001);
}

TEST(FigureTest, OctagonArea) {
    Octagon octagon;
    std::istringstream stream("0 2\n1 3\n2 3\n3 2\n3 1\n2 0\n1 0\n0 1\n");
    octagon.read(stream);
    
    double area = octagon.area();
    EXPECT_GT(area, 0);
    EXPECT_NEAR(area, 7.0, 1.0); 
}

TEST(FigureTest, FigureArrayOperations) {
    FigureArray array;
    
    Triangle* t = new Triangle();
    std::istringstream stream1("0 0\n4 0\n2 3\n");
    t->read(stream1);
    array.addFigure(t);
    
    EXPECT_EQ(array.size(), 1);
    EXPECT_NEAR(array.totalArea(), 6.0, 0.001);
    
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 0);
}

TEST(FigureTest, CloneAndEquality) {
    Triangle t1;
    std::istringstream stream("0 0\n4 0\n2 3\n");
    t1.read(stream);
    
    Triangle* t2 = t1.clone();
    EXPECT_TRUE(*t2 == t1);
    EXPECT_NEAR(t2->area(), 6.0, 0.001);
    delete t2;
}

TEST(FigureTest, ArrayOperatorAccess) {
    FigureArray array;
    Triangle* triangle_obj = new Triangle();
    std::istringstream stream("0 0\n4 0\n2 3\n");
    triangle_obj->read(stream);
    array.addFigure(triangle_obj);
    
    EXPECT_NEAR(array[0]->area(), 6.0, 0.001);
    Point center = array[0]->center();
    EXPECT_NEAR(center.coord_x, 2.0, 0.001);
}

TEST(FigureTest, MoveSemantics) {
    Triangle first_triangle;
    std::istringstream stream("0 0\n4 0\n2 3\n");
    first_triangle.read(stream);
    
    Triangle second_triangle = std::move(first_triangle);
    EXPECT_NEAR(second_triangle.area(), 6.0, 0.001);
}

TEST(FigureTest, FigureArrayMove) {
    FigureArray first_array;
    Triangle* triangle_obj = new Triangle();
    std::istringstream stream("0 0\n4 0\n2 3\n");
    triangle_obj->read(stream);
    first_array.addFigure(triangle_obj);
    
    FigureArray second_array = std::move(first_array);
    EXPECT_EQ(second_array.size(), 1);
    EXPECT_EQ(first_array.size(), 0);
    EXPECT_NEAR(second_array[0]->area(), 6.0, 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}