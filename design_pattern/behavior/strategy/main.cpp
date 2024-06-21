#include "calculator.h"

//g++ *.cpp -std=c++11
int main()
{
    Operation *operation1 = new Add();
    Operation *operation2 = new Div();
    Calculator calculator1(*operation1);
    Calculator calculator2(*operation2);
    calculator1.calculate(10, 2);
    calculator2.calculate(10, 2);

    delete operation1;
    delete operation2;
    operation1 = nullptr;
    operation2 = nullptr;
    return 0;
}