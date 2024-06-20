#ifndef PHONE_H_
#define PHONE_H_
#include <iostream>
class Phone
{
public:
    virtual std::string function() = 0;
    virtual std::string surface() = 0; // 外壳
};

class iPhone : public Phone
{
public:
    virtual std::string function() override
    {
        return "iPhone 基础功能";
    }
    virtual std::string surface() override
    {
        return "iPhone 裸机";
    }
};

class Nokia : public Phone
{
public:
    virtual std::string function() override
    {
        return "Nokia 基础功能";
    }
    virtual std::string surface() override
    {
        return "Nokia 裸机";
    }
};

#endif