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
 *
 * global，static变量：
 * 这种自动赋值只适用于未初始化的全局变量和静态变量
 * .bss段是可执行文件中的一部分，其中存储了未初始化的全局变量和静态变量，
 * 而已初始化的全局变量和静态变量存储在.data段中。
 *
 * 全局对象 全局自定义变量：
 * 全局对象构造函数>main>全局对象析构函数，压栈执行
 *
 * 将main函数的参数argc，argv等传递给main函数，然后才真正运行main函数
 *
 *
 */

#include <iostream>

class A {
public:
    A() {
        std::cout << "A constructor" << std::endl;
    }
    ~A() {
        std::cout << "A destructor" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "B constructor" << std::endl;
    }
    ~B() {
        std::cout << "B destructor" << std::endl;
    }
};

//全局对象 全局自定义变量
A a;
B b;

/**
 * 全局对象构造函数
 * main
 * 全局对象析构函数，压栈执行
 *
 *  A constructor
    B constructor
    Main function
    B destructor
    A destructor
 * @return
 */
int main() {
    std::cout << "Main function" << std::endl;
    return 0;
}