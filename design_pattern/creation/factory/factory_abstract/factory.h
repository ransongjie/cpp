#ifndef _FACTORY_H_
#define _FACTORY_H_
#include "shape.h"
#include "color.h"
enum EFACTORY{SHAPE_FACTORY,COLOR_FACTORY};

//抽象工厂
class Factory{
    public:
    virtual Shape *buildShape(enum ESHAPE eshape)=0;
    virtual Color *buildColor(enum ECOLOR ecolor)=0;
};

//具体工厂
class ShapeFactory:public Factory
{
public:
    // 返回局部对象指针
    Shape *buildShape(enum ESHAPE eshape) override;
    Color *buildColor(enum ECOLOR ecolor) override;
};

class ColorFactory:public Factory
{
public:
    Shape *buildShape(enum ESHAPE eshape) override;
    Color *buildColor(enum ECOLOR ecolor) override;
};
#endif