#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <unordered_map>
#include <string>
class Shape
{
public:
    virtual void draw() = 0;
    ~Shape() {}
};
class Circle : public Shape
{
private:
    std::string color;
    float x;
    float y;
    float radius;

public:
    Circle(const std::string &color) : color(color) {}
    void setX(float x);
    void setY(float y);
    void setRadius(float radius);
    float getX() const;
    float getY() const;
    float getRadius() const;
    void draw() override;
    ~Circle() {}
};
class ShapeFactory
{
public:
    static std::unordered_map<std::string, Shape *> csMap;
    static Circle *getCircle(std::string color);
    ~ShapeFactory() {}
};
#endif