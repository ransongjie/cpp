#include <iostream>
using namespace std;
/**
 * 宏定义和函数的区别
 */
//宏定义方式
#define MAX(a, b) (a > b ? a : b)

//函数方式
int max(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int x = 10, y = 20;
    int max1 = MAX(x, y);
    std::cout << "max1 is " << max1 << std::endl;

    int max2 = max(x, y);
    std::cout << "max2 is " << max2 << std::endl;
    return 0;
}