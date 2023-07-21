#include <iostream>

using namespace std;

/**
 * 都从低地址开始存储
 * 大端存储：高字节存储在低地址中
 * 小端存储：低字节存储在低地址中
 */
int main() {
    unsigned int num = 0x12345678; // 一个32位的整数
    unsigned char *ptr = (unsigned char *) &num; // 将整数的地址强制转换为指向字符型的指针

    printf("num = 0x%x\n", num);

    // 小端存储方式：12 34 56 78
    printf("little: \n");
    printf("%x %x %x %x\n", ptr[3], ptr[2], ptr[1], ptr[0]);

    // 大端存储方式: 78 56 34 12
    printf("big: \n");
    printf("%x %x %x %x\n", ptr[0], ptr[1], ptr[2], ptr[3]);

    return 0;
}