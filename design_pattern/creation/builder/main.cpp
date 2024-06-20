#include <iostream>
#include "./item/item.h"

// 
int main()
{
    MealBuilder mealBuilder = new MealBuilder();

    Meal vegMeal = mealBuilder.prepareVegMeal();
    std::cout << "套餐 Veg Meal" << std::endl;
    vegMeal.showItems();
    std::cout << "Total Cost: " << vegMeal.getCost() << std::endl;

    std::cout << "#########################" << std::endl;

    Meal nonVegMeal = mealBuilder.prepareNonVegMeal();
    std::cout << "套餐 Non-Veg Meal" << std::endl;
    nonVegMeal.showItems();
    std::cout << "Total Cost: " << nonVegMeal.getCost() << std::endl;
}