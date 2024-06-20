#ifndef _DRINK_H_
#define _DRINK_H_
#include "item.h"
#include "packing.h"

class Drink : public Item
{
public:
    Packing *packing() override
    {
        return new Bottle();
    }
    virtual std::string name() override = 0;
    virtual float price() override = 0;
};

class Coke : public Drink
{
public:
    std::string name() override;

    float price() override;
};

class Pepsi : public Drink
{
public:
    std::string name() override;

    float price() override;
};

#endif