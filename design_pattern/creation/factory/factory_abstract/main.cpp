#include <iostream>
#include "factory_builder.h"
using namespace std;

/*
g++ shape.cpp color.cpp factory.cpp factory_builder.cpp main.cpp
*/

int main()
{
    // 创建工厂
    Factory *shapeFactory = FactoryBuilder::buildFactory(SHAPE_FACTORY);

    // 创建产品
    Shape *circle = shapeFactory->buildShape(CIRCLE);
    circle->draw();
    Shape *square = shapeFactory->buildShape(SQUARE);
    square->draw();
    Shape *rectangle = shapeFactory->buildShape(RECTANGLE);
    rectangle->draw();

    delete rectangle;
    rectangle = nullptr;
    delete square;
    square = nullptr;
    delete circle;
    circle = nullptr;
    delete shapeFactory;
    shapeFactory = nullptr;

    return 0;
}