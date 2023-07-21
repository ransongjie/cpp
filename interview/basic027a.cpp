#include <iostream>
using namespace std;

/**
 * 引用动态绑定 定义时初始化即可
 * 虚函数才可以动态绑定
 */

class Base
{
public:
    virtual void  fun()
    {
        cout << "base :: fun()" << endl;
    }
};

class Son : public Base
{
public:
    virtual void  fun()
    {
        cout << "son :: fun()" << endl;
    }
    void func()
    {
        cout << "son :: not virtual function" <<endl;
    }
};

int main()
{
    Son s;
    Base& b = s; // 基类类型引用绑定已经存在的Son对象，引用必须初始化
    s.fun();     // son::fun()
    b.fun();     // son :: fun()
    return 0;
}
