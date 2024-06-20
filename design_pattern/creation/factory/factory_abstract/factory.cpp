#include "factory.h"

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
Color *ShapeFactory::buildColor(enum ECOLOR ecolor) { return nullptr; }

Shape *ColorFactory::buildShape(enum ESHAPE eshape) { return nullptr; }
Color *ColorFactory::buildColor(enum ECOLOR ecolor)
{
    switch (ecolor)
    {
    case RED:
        return new Red();
        break;
    case BLUE:
        return new Blue();
        break;
    case GREEN:
        return new Green();
        break;
    default:
        return nullptr;
        break;
    }
}