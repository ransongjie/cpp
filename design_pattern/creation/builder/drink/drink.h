#ifndef _DRINK_H_
#define _DRINK_H_
#include "../item/item.h"
#include "../packing/packing.h"

class Drink : public Item
{
public:
    Packing *packing() override
    {
        return new Bottle();
    }
    virtual std::string name() = 0;
    virtual float price() = 0;
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