#include <iostream>
#include <stddef.h>
using namespace std;

/**
 * 结构体成员向对于结构体开头的偏移量
 */

struct S
{
    int x;
    char y;
    int z;
    double a;
};

int main()
{
    cout << offsetof(S, x) << endl; // 0
    cout << offsetof(S, y) << endl; // 4
    cout << offsetof(S, z) << endl; // 8
    cout << offsetof(S, a) << endl; // 16 结构体对齐按max(成员) double=8B
    return 0;
}