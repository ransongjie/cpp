#include "shape.h"
#include <iostream>
void Circle::draw()
{
    std::cout << "Circle" << std::endl;
}

void Square::draw()
{
    std::cout << "Square" << std::endl;
}

void ShapeFacade::drawCircle()
{
    circle.draw();
}

void ShapeFacade::drawSquare()
{
    square.draw();
}