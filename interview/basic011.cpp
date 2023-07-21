#include <iostream>

using namespace std;

/**
 * 初始化和赋值的区别
 * 基本类型，没有区别
 * 类，有区别
 * - 初始化，可能调用拷贝构造函数
 * - 赋值，可能重新=运算符
 */
class A {
public:
    int num1;
    int num2;
public:
    A(int a = 0, int b = 0) : num1(a), num2(b) {};

    A(const A &a) {};

    //重载 = 号操作符函数
    A &operator=(const A &a) {
        num1 = a.num1 + 1;
        num2 = a.num2 + 1;
        return *this;
    };
};

int main() {
    A a(1, 1);
    A a1 = a; //拷贝初始化操作，调用拷贝构造函数，没调用重载的=运算符
    A b;
    b = a;//赋值操作，调用了重载的=运算符
    return 0;
}
