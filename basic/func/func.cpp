#include <iostream>
using namespace std;
//函数声明
int max(int num1, int num2);
int max2(int num1, int num2=200);
void test();

int main(){
    int num=max(10,30);
    cout<<num<<endl;

    num=max2(10);
    cout<<num<<endl;

    test();
}

//注意：指针传递，引用传递，值传递
//函数实现
int max(int num1, int num2){
    return num1>num2?num1:num2;
}

//参数默认值 声明处写默认值
int max2(int num1, int num2){
    return num1>num2?num1:num2;
}

//lambda表达式
void test(){
    int x = 10;
    //[]外部变量捕获方式 值捕获, 引用捕获 [x, &y], [=](隐式值捕获)
    //值捕获 不影响外部参数
    auto func = [x]() { return x * 2; };
    int a=func();
    cout<<a<<endl;
    cout<<x<<endl;
    //引用捕获 影响外部参数
    auto func2= [&x]() {return x * 2;};
    int b=func2();
    cout<<b<<endl;
    cout<<x<<endl;
}