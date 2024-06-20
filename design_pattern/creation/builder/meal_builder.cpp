#include "item.h"
#include "burger.h"
#include "drink.h"

Meal* MealBuilder::prepareVegMeal()
{
    Meal *meal = new Meal();
    meal->addItem(new VegBurger());
    meal->addItem(new Coke());
    return meal;
}
Meal* MealBuilder::prepareNonVegMeal()
{
    Meal *meal = new Meal();
    meal->addItem(new ChickenBurger());
    meal->addItem(new Pepsi());
    return meal;
}