#include <iostream>
#include "shape.h"
using namespace std;

void Circle::draw()
{
    cout << "draw circle" << endl;
}

void Square::draw()
{
    cout << "draw square" << endl;
}

void Rectangle::draw()
{
    cout << "draw rectangle" << endl;
}

Shape *ShapeFactory::buildShape(enum ESHAPE eshape)
{
    if (eshape == CIRCLE)
    {
        return new Circle();
    }
    else if (eshape == SQUARE)
    {
        return new Square();
    }
    else if (eshape == RECTANGLE)
    {
        return new Rectangle();
    }
    else
    {
        return nullptr;
    }
}
