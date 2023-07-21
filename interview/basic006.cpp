#include <iostream>

using namespace std;
/**
 *
 * 当结构体或类中的成员变量的总大小不是对齐值的倍数时，
 * 编译器会在成员之间插入填充字节（padding），
 * 以确保结构体或类的内存布局满足对齐要求
 *
 * 内存对齐:
 * - 结构体内成员按照声明顺序存储
 * - 第一个成员地址和整个结构体地址相同
 * - 默认，结构体内存对齐=max(成员)
 * - ！成员变量按照 结构体内存进行对齐，结构体内存大小 是 结构体内存对齐的整数倍
 *
 * alignas生效
 * - alignas(k),k>=max(成员)
 *
 * alignas失效
 * - alignas(k),k<max(成员)
 */

// alignas 生效的情况
//结构体默认=max(成员) 对齐
struct Info {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

//指定结构体按4字节对齐
struct alignas(4) Info2 {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

struct Info3 {
    uint8_t a;
    uint32_t b;
    uint8_t c;
};

//gcc编译报错，Requested alignment is less than minimum alignment of 4 for type 'Info4'
//struct alignas(2) Info4 {
//    uint8_t a;
//    uint32_t b;
//    uint8_t c;
//};

int main() {
    //6=2(结构体 uint16_t)+2(uint16_t)+2(uint8_t+uint8_t)
    std::cout << sizeof(Info) << std::endl;   // 6
    std::cout << alignof(Info) << std::endl;  // 2

    //8=2(结构体 指定4)+4(uint16_t+uint8_t+uint8_t)
    std::cout << sizeof(Info2) << std::endl;   // 8
    std::cout << alignof(Info2) << std::endl;  // 4

    //12=2(结构体 uint32_t)+4(uint32_t)+4(uint8_t+uint8_t)
    std::cout << sizeof(Info3) << std::endl;   // 12
    std::cout << alignof(Info3) << std::endl;  // 4
}
