#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <string>
#include <unordered_map>

class Shape
{
private:
    int id;

protected:
    std::string type;
    // 内联函数，显式调用函数，初始化列表，入参常引用
    inline explicit Shape(const std::string &type) : type(type) {}

public:
    void setId(int id);
    inline Shape(int id, std::string type) : id(id), type(type) {}
    int getId() const; // 常成员函数
    std::string getType() const;
    virtual void draw() = 0; // 抽象类不能实例化
    virtual Shape *clone() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    // 初始化列表
    Circle() : Shape("Circle") {}
    inline Circle(const Circle &o) : Shape(o.getId(), o.getType()) {} // 拷贝构造函数
    Shape *clone() const override;
    void draw() override;
};

class Square : public Shape
{
public:
    Square() : Shape("Square") {}
    inline Square(const Square &o) : Shape(o.getId(), o.getType()) {}
    Shape *clone() const override;
    void draw() override;
};

class ShapeCache
{
private:
    // 模拟数据库
    // 声明静态成员变量
    static std::unordered_map<int, Shape *> shapeMap;

public:
    static void loadCache();
    static Shape *getShape(int shapeId);
};
#endif