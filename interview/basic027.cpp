#include <iostream>

using namespace std;

/**
 * 静态绑定 编译时绑定，
 * 动态绑定 运行时绑定，virtual函数 多态
 *
 * 指针动态绑定
 * 虚函数才可以动态绑定
 */

class A
{
public:
    /*virtual*/ void func() { std::cout << "A::func()\n"; }
};

class B : public A
{
public:
    void func() { std::cout << "B::func()\n"; }
};

class C : public A
{
public:
    void func() { std::cout << "C::func()\n"; }
};

int main()
{
    C* pc = new C(); //pc的静态类型是它声明的类型C*，动态类型也是C*；
    B* pb = new B(); //pb的静态类型和动态类型也都是B*；
    A* pa = pc;      //pa的静态类型是它声明的类型A*，动态类型是pa所指向的对象pc的类型C*；
    pa = pb;         //pa的动态类型可以更改，现在它的动态类型是B*，但其静态类型仍是声明时候的A*；
    C *pnull = NULL; //pnull的静态类型是它声明的类型C*,没有动态类型，因为它指向了NULL；

    pa->func();      //A::func() pa的静态类型永远都是A*，不管其指向的是哪个子类，都是直接调用A::func()；
    pc->func();      //C::func() pc的动、静态类型都是C*，因此调用C::func()；
    pnull->func();   //C::func() 不用奇怪为什么空指针也可以调用函数，因为这在编译期就确定了，和指针空不空没关系；
    return 0;
}