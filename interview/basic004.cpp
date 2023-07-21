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
 * gcc扩展：
 * __attribute__((constructor))
 * main
 * __attribute__((destructor))
 */

void my_constructor() __attribute__((constructor));

void my_constructor() {
    cout << "__attribute__((constructor))" << endl;
}

void my_destructor() __attribute__((destructor));

void my_destructor() {
    cout << "__attribute__((destructor))" << endl;
}

/**
 * 执行结果
 * __attribute__((constructor))
    Main function
    __attribute__((destructor))
 * @return
 */
int main() {
    std::cout << "Main function" << std::endl;
    return 0;
}