#ifndef _SHAPE_H_
#define _SHAPE_H_

enum ESHAPE
{
    CIRCLE = 0,
    RECTANGLE,
    SQUARE
};
// 接口
class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw() override;
};

class Square : public Shape
{
public:
    void draw() override;
};

class Rectangle : public Shape
{
public:
    void draw() override;
};

class ShapeFactory
{
public:
    // 返回局部对象指针
    Shape *buildShape(enum ESHAPE eshape);
};

#endif