#include <iostream>
using namespace std;
//
// Created by xcrj on 2023/7/16.
//
/**
 * main执行之前和之后执行的代码可能是什么？
 *
 * global，static变量：
 * 在程序运行期间，这些变量的值将存储在.data段中。
 * 在程序运行期间，这些变量的位置和大小都是固定的，因此它们的值在整个程序的运行期间都是不变的。
 */

int global_var = 10; // 全局变量，初始化为10

void foo()
{
    static int static_var = 20; // 静态变量，初始化为20
    std::cout << "Global variable: " << global_var << std::endl;
    std::cout << "Static variable: " << static_var << std::endl;
    static_var++; // 修改静态变量的值
}

int main()
{
    foo(); // 输出 Global variable: 10, Static variable: 20
    foo(); // 输出 Global variable: 10, Static variable: 21
    foo(); // 输出 Global variable: 10, Static variable: 22
    return 0;
}