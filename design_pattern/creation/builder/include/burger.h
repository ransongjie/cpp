#ifndef _BURGER_H_
#define _BURGER_H_
#include <string>
#include "item.h"
#include "packing.h"

class Burger : public Item
{
public:
    Packing *packing() override
    {
        return new Wrapper();
    }
    virtual std::string name() override = 0;
    virtual float price() override = 0;
};

class ChickenBurger : public Burger
{
public:
    std::string name() override;
    float price() override;
};

class VegBurger : public Burger
{
public:
    std::string name() override;
    float price() override;
};
#endif