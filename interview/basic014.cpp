#include <iostream>

using namespace std;

/**
 * 隐藏
 * 派生类 非虚函数 隐藏 基类 非虚函数
 *
 * 派生类 虚函数 隐藏 基类 虚函数
 */
// 父类
class A {
public:
    virtual void fun(int a) { // 虚函数
        cout << "This is A fun " << a << endl;
    }

    void add(int a, int b) {
        cout << "This is A add " << a + b << endl;
    }
};

// 子类
class B : public A {
public:
    void fun(int a) override {  // 覆盖
        cout << "this is B fun " << a << endl;
    }

    void add(int a) {   // 隐藏
        cout << "This is B add " << a + a << endl;
    }
};

int main() {
    // 而基类指针只能调用基类的被隐藏函数，无法识别派生类中的隐藏函数。

    //基类指针指向派生类对象
    //多态 virtual和override
    A *p = new B();
    p->fun(1);      // 基类指针调用 派生类 覆盖函数
    p->A::fun(1);   // 基类指针调用 基类 被覆盖虚函数

    //隐藏
    p->add(1, 2); // 基类指针调用 基类 被隐藏函数
    p->add(1);      // 基类指针调用 派生类 函数
    p->B::add(1);   // 基类指针调用 派生类 函数

    return 0;
}
