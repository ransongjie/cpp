#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>
#include <vector>
#include "../packing/packing.h"

class Item
{
public:
    virtual Packing *packing() = 0; // 返回局部对象的指针
    virtual std::string name() = 0;
    virtual float price() = 0;
};

class Meal
{
private:
    std::vector<Item *> items;

public:
    void addItem(Item *item);
    void showItems();
    float getCost();
};

class MealBuilder
{
public:
    Meal prepareVegMeal();
    Meal prepareNonVegMeal();
};

#endif