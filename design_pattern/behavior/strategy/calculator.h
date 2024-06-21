#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_
#include <iostream>
class Operation
{
public:
    Operation() {}
    ~Operation() {}
    virtual void operate(int a, int b) = 0;
};

class Add : public Operation
{
public:
    Add() {}
    ~Add() {}
    void operate(int a, int b) override;
};

class Sub : public Operation
{
public:
    Sub() {}
    ~Sub() {}
    void operate(int a, int b) override;
};

class Mul : public Operation
{
public:
    Mul() {}
    ~Mul() {}
    void operate(int a, int b) override;
};

class Div : public Operation
{
public:
    Div() {}
    ~Div() {}
    void operate(int a, int b) override;
};

class Calculator
{
private:
    Operation &operation;

public:
    Calculator(Operation &operation) : operation(operation) {}
    ~Calculator() {}
    void calculate(int a, int b);
};
#endif