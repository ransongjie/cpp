#include <iostream>
using namespace std;

/**
 * 使用成员初始化列表构造对象更快的原因
 * 若在构造函数内部构造对象 会
 * 1. 调用默认构造函数，创建对象
 * 2. 调用赋值构造，给对象赋值
 */
#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << "默认构造函数A()" << endl;
    }
    A(int a)
    {
        value = a;
        cout << "A(int "<<value<<")" << endl;
    }
    A(const A& a)
    {
        value = a.value;
        cout << "拷贝构造函数A(A& a):  "<<value << endl;
    }
    int value;
};

class B
{
public:
    B() : a(1)
    {
        b = A(2);
    }
    A a;
    A b;
};
int main()
{
    B b;
}

//输出结果：
//A(int 1)

//默认构造函数A()
//A(int 2)
