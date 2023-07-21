#include <iostream>
using namespace std;
/*
 类型提升，类型降低
 */
int main(){
    // 整数 整数 相互转换
    int a=10;
    long int la=a;
    
    long int lb=20;
    int b=lb;

    //浮点数 浮点数 相互转换
    float c=10.2;
    double dc=c;
    cout<<dc<<endl;

    double d=20.3;
    float fd=d;
    cout<<fd<<endl;

    // 整数 浮点数 相互转换
    int e=10;
    float fe=e;
    cout<<fe<<endl;

    float f=23.3;
    int fi=int(f);//强制类型转换 也称 cast运算符
    cout<<fi<<endl;
}