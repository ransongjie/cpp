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
 */

int global_int; // 未初始化的全局int变量
bool global_bool; // 未初始化的全局bool变量
char global_char; // 未初始化的全局char变量
int* global_ptr; // 未初始化的全局指针变量

void foo(){
    static int static_int; // 未初始化的静态int变量
    static bool static_bool; // 未初始化的静态bool变量
    static char static_char; // 未初始化的静态char变量
    static int* static_ptr; // 未初始化的静态指针变量

    std::cout << "Static int: " << static_int << std::endl;//0
    std::cout << "Static bool: " << static_bool << std::endl;//0
    std::cout << "Static char: " << static_char << std::endl;//\0
    std::cout << "Static pointer: " << static_ptr << std::endl;//NULL 0
}

int main()
{
    std::cout << "Global int: " << global_int << std::endl;//0
    std::cout << "Global bool: " << global_bool << std::endl;//0
    std::cout << "Global char: " << global_char << std::endl;//\0
    std::cout << "Global pointer: " << global_ptr << std::endl;//NULL 0
    foo();
    return 0;
}