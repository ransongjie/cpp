#include "cmd.h"

void Solider::shootPlane()
{
    std::cout << "Shoot plane" << std::endl;
}

void Solider::shootTank()
{
    std::cout << "Shoot tank" << std::endl;
}

void ShootPlane::execute()
{
    solider.shootPlane();
}

void ShootTank::execute()
{
    solider.shootTank();
}

void Officer::add(Order *order)
{
    orders.push_back(order);
}
void Officer::del(Order *order)
{
    auto it = std::find(orders.begin(), orders.end(), order);
    if (it == orders.end())
    {
        return;
    }
    orders.erase(it);
}
void Officer::make()
{
    for (int i = 0; i < orders.size(); i++)
    {
        orders[i]->execute();
    }
}