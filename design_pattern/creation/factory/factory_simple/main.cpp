#include <iostream>
#include "shape.h"
using namespace std;
/*
g++ shape.cpp main.cpp
*/
int main()
{
    // 对象分配在栈中
    ShapeFactory shapeFactory;

    Shape *circle = shapeFactory.buildShape(CIRCLE);
    circle->draw();

    Shape *square = shapeFactory.buildShape(SQUARE);
    square->draw();

    Shape *rectangle = shapeFactory.buildShape(RECTANGLE);
    rectangle->draw();

    // 避免悬空指针
    delete rectangle;
    rectangle = nullptr;
    delete square;
    square = nullptr;
    delete circle;
    circle = nullptr;

    return 0;
}