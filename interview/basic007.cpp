#include <iostream>
using namespace std;
/**
 * 指针与引用的区别
 */
int main(){
    //编译器自动转换为指针，int * const b = &a;
    int a = 10;
    int &b = a;

    //编译器自动解引用（引用解为指针），*b = 20
    b=20;
}