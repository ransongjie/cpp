#include <iostream>
using namespace std;
/**
 * 重写 虚函数
 * 重载 运算符
 */

class Base {
public:
    //virtual 声明
    virtual void print() {
        std::cout << "Base::print() called" << std::endl;
    }
};

class Derived : public Base {
public:
    //override 显式声明是一个重写函数
    void print() override {
        std::cout << "Derived::print() called" << std::endl;
    }
};

//重载运算符
class A{
    public:
        string name;
        A(){}
        A(string name){
            this->name=name;
        }
        A operator+(const A& a){
            return A(this->name+a.name);
        }
};

int main() {
    //重写 虚函数
    //new方式创建对象指针
    Base* ptr = new Derived();
    ptr->print();
    delete ptr;
    
    //重载运算符
    A a("xcrj");
    A a1("xcrj2");
    A addAA=a+a1;
    cout<<addAA.name<<endl;
}