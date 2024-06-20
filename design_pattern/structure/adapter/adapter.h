#ifndef _ADAPTER_H_
#define _ADAPTER_H_
#include "charger.h"
#include <iostream>

// ChinaCharger上层适配对象
class Adapter : public ChinaCharger
{
public:
    Adapter() : euCharger(new EUCharger()) {}
    //存在指针成员一定要写析构函数
    ~Adapter(){
        delete euCharger;
        euCharger=nullptr;
    }
    virtual void charge() override
    {
        std::cout << "Charging by Adapter " << std::endl;
        euCharger->charge();
    }

private:
    // 下层适配对象
    EUCharger *euCharger;
};

#endif