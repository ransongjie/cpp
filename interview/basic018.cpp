#include <iostream>
using namespace std;

/**
 * 判断是大端存储还是小端存储
 * 方法1：int(至少占用4B) char(至少占用1B)强制转换
 * 方法2：union联合体的重叠式存储，endian联合体占用内存=max(成员最大内存)
 */
union endian
{
    int a;
    char ch;
};

int main()
{
    endian value;
    value.a = 0x1234;
    //a和ch共用4字节的内存空间
    if (value.ch == 0x12)
        cout << "big endian"<<endl;
    else if (value.ch == 0x34)
        cout << "little endian"<<endl;
}
