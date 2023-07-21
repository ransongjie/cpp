#include <iostream>

using namespace std;
//
// Created by xcrj on 2023/7/15.
//
int test1(){
    int a=10;
    int * const p =&a;//const (p)
    *p = 20;
//    p=&b;
}
int test2(){
    int a=10;
    int b=10;
    const int *p=&a;//const (*p)
//    *p = 20;
    p=&b;
}
int main(){

}