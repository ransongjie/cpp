#ifndef _CMD_H_
#define _CMD_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solider
{
private:
    const std::string &name;

public:
    Solider(const std::string &name) : name(name) {}
    virtual ~Solider() {}
    void shootPlane();
    void shootTank();
};
class Order
{
protected:
    Solider &solider;

public:
    Order(Solider &solider) : solider(solider) {}
    virtual ~Order() {}
    virtual void execute() = 0;
};

class ShootPlane : public Order
{
public:
    ShootPlane(Solider &solider) : Order(solider) {}
    virtual ~ShootPlane() {}
    void execute() override;
};

class ShootTank : public Order
{
public:
    ShootTank(Solider &solider) : Order(solider) {}
    virtual ~ShootTank() {}
    void execute() override;
};

class Officer
{
private:
    std::vector<Order *> orders;

public:
    Officer() {}
    virtual ~Officer() {}
    void add(Order *order);
    void del(Order *order);
    void make(); // 下命令
};

#endif