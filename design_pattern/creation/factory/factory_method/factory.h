#ifndef _FACTORY_H_
#define _FACTORY_H_
#include "shape.h"

class Factory{
    public:
    virtual Shape* buildShape()=0;
};

class CircleFactory:public Factory{
public:
    Shape* buildShape() override;
};

class SquareFactory:public Factory{
public:
    Shape* buildShape() override;
};

class RectangleFactory:public Factory{
public:
    Shape* buildShape() override;
};
#endif