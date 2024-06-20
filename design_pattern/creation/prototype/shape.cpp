#include "./include/shape.h"
#include <iostream>

// Shape
void Shape::setId(int id)
{
    this->id = id;
}
int Shape::getId() const
{
    return this->id;
}
std::string Shape::getType() const
{
    return this->type;
}

// Circle
void Circle::draw()
{
    std::cout << "Draw circle" << std::endl;
}

Shape *Circle::clone() const
{
    return new Circle(*this);
}

// Square
void Square::draw()
{
    std::cout << "Draw square" << std::endl;
}

Shape *Square::clone() const
{
    return new Square(*this);
}

// ShapeCache

// 定义静态成员变量
std::unordered_map<int, Shape *> ShapeCache::shapeMap;

Shape *ShapeCache::getShape(int shapeId)
{
    auto it = ShapeCache::shapeMap.find(shapeId);
    if (it != ShapeCache::shapeMap.end())
    {
        return it->second->clone();
    }
    else
    {
        return nullptr;
    }
}
void ShapeCache::loadCache()
{
    Circle *circle = new Circle();
    circle->setId(1);
    shapeMap[circle->getId()] = circle;

    Square *square = new Square();
    square->setId(2);
    shapeMap[square->getId()] = square;
}