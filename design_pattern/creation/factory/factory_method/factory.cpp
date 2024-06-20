#include "factory.h"

Shape *CircleFactory::buildShape()
{
    return new Circle();
}

Shape *SquareFactory::buildShape()
{
    return new Square();
}

Shape *RectangleFactory::buildShape()
{
    return new Rectangle();
}