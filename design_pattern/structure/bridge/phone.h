#ifndef _PHONE_H_
#define _PHONE_H_
#include "os.h"
#include <iostream>

class Phone
{
public:
    virtual void getOS() = 0;
};

class iPhone : public Phone
{
public:
    iPhone(OS *os)
    {
        this->os = os;
    }
    ~iPhone()
    {
        delete os;
        os=nullptr;
    }
    virtual void getOS() override
    {
        std::cout << this->os->OSName() << std::endl;
    }

private:
    // 桥接模式
    OS *os;
};

class Nokia : public Phone
{
public:
    Nokia(OS *os)
    {
        this->os = os;
    }
    ~Nokia()
    {
    }

    virtual void getOS() override
    {
        std::cout << this->os->OSName() << std::endl;
    }

private:
    OS *os;
};
#endif