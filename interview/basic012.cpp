#include <iostream>
using namespace std;

/**
 * 隐藏
 * 派生类 非虚函数 隐藏 基类 非虚函数
 */
//父类
class A{
public:
    void fun(int a){
        cout << "A中的fun函数" << endl;
    }
};
//子类
class B : public A{
public:
    //隐藏父类的fun函数
    void fun(int a){
        cout << "B中的fun函数" << endl;
    }
};
int main(){
    B b;
    b.fun(2); //调用的是B中的fun函数
    b.A::fun(2); //调用A中fun函数
    return 0;
}

