#ifndef _SHAPE_H_
#define _SHAPE_H_
class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw();
};

class Square : public Shape
{
public:
    void draw();
};

class ShapeFacade
{
private:
    Circle circle;
    Square square;

public:
    void drawCircle();
    void drawSquare();
};

#endif