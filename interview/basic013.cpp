#include <iostream>
using namespace std;

/**
 * 隐藏：只要名字一样就隐藏了，参数数量和类型都可以不同
 * 派生类 非虚函数 隐藏 基类 非虚函数
 *
 * 派生类 虚函数 隐藏 基类 虚函数
 */
//父类
class A{
public:
    virtual void fun(int a){
        cout << "A中的fun函数" << endl;
    }
};
//子类
class B : public A{
public:
    //隐藏父类的fun函数
    virtual void fun(char* a){
        cout << "A中的fun函数" << endl;
    }
};
int main(){
    B b;
    b.A::fun(2); //调用A中fun函数
    b.fun(2); //报错，调用的是B中的fun函数，参数类型不对
    return 0;
}