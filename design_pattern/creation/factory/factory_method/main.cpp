#include <iostream>
#include "factory.h"
using namespace std;
/*
g++ shape.cpp factory.cpp main.cpp
*/
int main(){
    //创建具体工厂生产具体产品
    CircleFactory circleFactory;
    Shape* circle=circleFactory.buildShape();
    circle->draw();

    SquareFactory squareFactory;
    Shape* square=squareFactory.buildShape();
    square->draw();

    RectangleFactory rectangleFactory;
    Shape* rectangle=rectangleFactory.buildShape();
    rectangle->draw();

    delete rectangle;
    rectangle = nullptr;
    delete square;
    square = nullptr;
    delete circle;
    circle = nullptr;

    return 0;
}