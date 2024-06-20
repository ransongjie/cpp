#include <iostream>
#include "item.h"

// g++ *.cpp -I ./include -std=c++11
int main()
{
    MealBuilder* mealBuilder = new MealBuilder();

    Meal* vegMeal = mealBuilder->prepareVegMeal();
    std::cout << "套餐 Veg Meal" << std::endl;
    vegMeal->showItems();
    std::cout << "Total Cost: " << vegMeal->getCost() << std::endl;

    std::cout << "#########################" << std::endl;

    Meal* nonVegMeal = mealBuilder->prepareNonVegMeal();
    std::cout << "套餐 Non-Veg Meal" << std::endl;
    nonVegMeal->showItems();
    std::cout << "Total Cost: " << nonVegMeal->getCost() << std::endl;

    //防止内存泄露
    delete nonVegMeal;
    delete vegMeal;
    delete mealBuilder;
    nonVegMeal=nullptr;
    vegMeal=nullptr;
    mealBuilder=nullptr;
}