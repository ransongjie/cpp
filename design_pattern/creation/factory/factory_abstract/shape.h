#ifndef _SHAPE_H_
#define _SHAPE_H_
// 需要在其它cpp文件中使用的内容，需要放入头文件中
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
    // 声明放在h文件中，实现放在cpp文件中
    // override放到声明中
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