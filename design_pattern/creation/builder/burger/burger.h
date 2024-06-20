#ifndef _BURGER_H_
#define _BURGER_H_

class Burger
{
public:
    Packing *packing() override
    {
        return new Wrapper();
    }
    virtual std::string name() = 0;
    virtual float price() = 0;
};

class ChickenBurger : public Burger
{
public:
    std::string name() override;
    float price() override;
}

class VegBurger : public Burger
{
public:
    std::string name() override;
    float price() override;
}
#endif