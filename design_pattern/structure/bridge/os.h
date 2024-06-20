#ifndef _OS_H_
#define _OS_H_
#include <iostream>

class OS
{
public:
    virtual std::string OSName() = 0;
};

class IOS : public OS
{
public:
    virtual std::string OSName() override
    {
        return "IOS";
    }
};

class SaiBian : public OS
{
public:
    //virtual从高层写到底层
    virtual std::string OSName() override
    {
        return "SaiBian";
    }
};

// 某个版本
class IOS511 : public IOS
{
public:
    virtual std::string GetOS()
    {
        return "IOS 5.1.1";
    }
};

class IOS1011 : public IOS
{
public:
    virtual std::string GetOS()
    {
        return "IOS 10.1.1";
    }
};

class SaiBian110 : public SaiBian
{
public:
    virtual std::string GetOS()
    {
        return "SaiBian 1.1.0";
    }
};

class SaiBian111 : public SaiBian
{
public:
    virtual std::string GetOS()
    {
        return "SaiBian 1.1.1";
    }
};

#endif