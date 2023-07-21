#include <iostream>
using namespace std;
/**
 * const成员变量
 * 只能在构造函数初始化列表中初始化
 * 不能在构造函数体中初始化
 */
class MyClass {
public:
    MyClass(int x, int y) : const_var(x), non_const_var(y) {
        cout<<"const int const_var: "<<const_var<<endl;
        cout<<"int non_const_var: "<<non_const_var<<endl;
    }
private:
    const int const_var;
    int non_const_var;
};

// 不能够在构造函数体中初始化const成员变量
class MyClass2 {
public:
    MyClass2(int x, int y) {
        const_var = x;
        non_const_var = y;
    }
private:
    const int const_var;
    int non_const_var;
};