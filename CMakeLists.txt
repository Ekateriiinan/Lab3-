cmake_minimum_required(VERSION 3.12)
project(Figures)

set(CMAKE_CXX_STANDARD 17)

add_executable(figures 
    main.cpp 
    Figure.cpp       
    Triangle.cpp 
    Square.cpp 
    Octagon.cpp 
    FigureArray.cpp
)

add_executable(tests 
    tests.cpp 
    Figure.cpp        
    Triangle.cpp 
    Square.cpp 
    Octagon.cpp 
    FigureArray.cpp
)

find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)