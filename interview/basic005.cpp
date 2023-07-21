#include <iostream>
using namespace std;
/**
 * 内存对齐:
 * 结构体内成员按照声明顺序存储
 * 第一个成员地址和整个结构体地址相同
 * 结构体内存对齐=最大成员
 */
struct MyStruct {
    int a;
    double b;
    char c;
};

int main() {
    MyStruct s;
    //24=8(结构体)+8(double)+8(int+char)
    std::cout << "Size of s: " << sizeof(MyStruct) << std::endl;//24
    std::cout << "Size of a: " << sizeof(s.a) << std::endl;//4
    std::cout << "Size of b: " << sizeof(s.b) << std::endl;//8
    std::cout << "Size of c: " << sizeof(s.c) << std::endl;//1

    std::cout << "Address of s: " << &s << std::endl;//0x531abff990
    std::cout << "Address of a: " << &(s.a) << std::endl;//0x531abff990, 第一个成员地址和整个结构体地址相同
    std::cout << "Address of b: " << &(s.b) << std::endl;
    std::cout << "Address of c: " << &(s.c) << std::endl;

    return 0;
}