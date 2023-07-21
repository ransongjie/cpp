#include <iostream>
using namespace std;

/**
 * mutable可变量
 */

//常函数
class person
{
    int m_A;
    mutable int m_B;//特殊变量 在常函数里值也可以被修改
public:
    void add() const//在函数里不可修改this指针指向的值 常量指针
    {
        m_A = 10;//错误  不可修改值，this已经被修饰为常量指针
        m_B = 20;//正确
    }
};

//常对象
class tea
{
public:
    int m_A;
    mutable int m_B;//特殊变量 在常函数里值也可以被修改
};

int main()
{
    const tea p = tea();//修饰常对象 不可修改类成员的值
    p.m_A = 10;//错误，被修饰了指针常量
    p.m_B = 200;//正确，特殊变量，修饰了mutable
}


