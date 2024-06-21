#include "calculator.h"

void Add::operate(int a, int b)
{
    std::cout << a + b << std::endl;
}

void Sub::operate(int a, int b)
{
    std::cout << a - b << std::endl;
}

void Mul::operate(int a, int b)
{
    std::cout << a * b << std::endl;
}

void Div::operate(int a, int b)
{
    std::cout << a / b << std::endl;
}

void Calculator::calculate(int a, int b)
{
    operation.operate(a, b);
}