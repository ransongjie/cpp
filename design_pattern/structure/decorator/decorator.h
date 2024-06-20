#ifndef DECORATOR_H_
#define DECORATOR_H_
#include "phone.h"

class Decorator : public Phone
{
public:
    explicit Decorator(Phone *phone)
    {
        this->phone = phone;
    }
    //
    virtual ~Decorator() {
        delete phone;
        phone=nullptr;
    }

    virtual std::string function() override
    {
        return phone->function();
    }

    virtual std::string surface() override
    {
        return phone->surface();
    }

    // protected 子类中可访问
protected:
    Phone *phone;
};

class iPhoneDecorator : public Decorator
{
public:
    // 初始化列表 调用父类构造函数
    iPhoneDecorator(Phone *phone) : Decorator(phone) {}

    virtual std::string function() override
    {
        return phone->function() + std::string("+ iPhone 充电时钟功能");
        ;
    }

    virtual std::string surface() override
    {
        return phone->surface() + std::string("+ iPhone 保护套");
    }
};

class NokiaDecorator : public Decorator
{
public:
    NokiaDecorator(Phone *phone) : Decorator(phone) {}

    virtual std::string function() override
    {
        return phone->function() + std::string("+ Nokia 隐私保护功能");
    }

    virtual std::string surface() override
    {
        return phone->surface() + std::string("+ Nokia 保护套");
    }
};
#endif