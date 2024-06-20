#ifndef _CHARGER_H_
#define _CHARGER_H_
#include <iostream>
class ChinaCharger
{
public:
    virtual void charge()
    {
        std::cout << "Charging by ChinaCharger " << std::endl;
    }
};

class EUCharger
{
public:
    virtual void charge()
    {
        std::cout << "Charging by EUCharger " << std::endl;
    }
};

#endif