#include <iostream>
#include "shape.h"
using namespace std;
/*
g++ shape.cpp main.cpp
*/
int main()
{
    Shape *circle = ShapeFactory::buildShape(CIRCLE);
    circle->draw();

    Shape *square = ShapeFactory::buildShape(SQUARE);
    square->draw();

    Shape *rectangle = ShapeFactory::buildShape(RECTANGLE);
    rectangle->draw();

    // 避免悬空指针
    delete rectangle;
    delete square;
    delete circle;
    rectangle = nullptr;
    square = nullptr;
    circle = nullptr;
    
    return 0;
}