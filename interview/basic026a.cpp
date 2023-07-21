#include <iostream>
#include <stddef.h>

using namespace std;

/**
 * 指定4字节对齐
 */

#pragma pack(4)

struct S {
    int x;
    char y;
    int z;
    double a;
};

int main() {
    cout << offsetof(S, x) << endl; // 0
    cout << offsetof(S, y) << endl; // 4
    cout << offsetof(S, z) << endl; // 8
    cout << offsetof(S, a) << endl; // 12
    cout << "=======" << endl;
    S s;
    cout << sizeof(s.x) << endl;//4
    cout << sizeof(s.y) << endl;//1 char=1B
    cout << sizeof(s.z) << endl;//4
    cout << sizeof(s.a) << endl;//8
}