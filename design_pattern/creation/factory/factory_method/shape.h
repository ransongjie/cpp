#ifndef _SHAPE_H_
#define _SHAPE_H_

enum ESHAPE
{
    CIRCLE = 0,
    RECTANGLE,
    SQUARE
};

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
#endif