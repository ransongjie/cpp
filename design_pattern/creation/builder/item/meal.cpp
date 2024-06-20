#include "item.h"
#include <iostream>

void Meal::addItem(Item *item)
{
    this->items.push_back(item);
}
void Meal::showItems()
{
    for (int i = 0; i < this->items.size(); i++)
    {
        std::cout << "Item: " + this->items[i]->name() + ", "
                  << "Packing: " + this->items[i]->packing()->pack() + ", "
                  << "Price: " << this->items[i]->price()
                  << std::endl;
    }
}
float Meal::getCost()
{
    float sum = 0.f;
    for (int i = 0; i < this->items.size(); i++)
    {
        sum += items[i]->price();
    }
    return sum;
}
