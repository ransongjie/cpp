#include "shape.h"
#include <iostream>

void Circle::setX(float x)
{
    this->x = x;
}
void Circle::setY(float y)
{
    this->y = y;
}
void Circle::setRadius(float radius) { this->radius = radius; }
float Circle::getX() const { return this->x; }
float Circle::getY() const { return this->y; }
float Circle::getRadius() const { return this->radius; }
void Circle::draw()
{
    std::cout << "Circle: Draw() [Color : " + color + ", x : " << x << ", y :" << y << ", radius :" << radius << std::endl;
}

std::unordered_map<std::string, Shape *> ShapeFactory::csMap;
Circle *ShapeFactory::getCircle(std::string color)
{
    auto it = ShapeFactory::csMap.find(color);
    if (it == ShapeFactory::csMap.end())
    {
        Shape *shape = new Circle(color);
        csMap[color] = shape;
        return dynamic_cast<Circle *>(shape);
    }
    return dynamic_cast<Circle *>(it->second); // 类型向下转换
}
