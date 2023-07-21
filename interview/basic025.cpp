#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/**
 * cpp函数调用压栈过程
 * 压栈main函数
 * 先访问的先压栈
 */

int f(int n)
{
    cout << n << endl;
    return n;
}

void func(int param1, int param2)
{
    int var1 = param1;
    int var2 = param2;
    printf("var1=%d,var2=%d", f(var1), f(var2));//如果将printf换为cout进行输出，输出结果则刚好相反
}

int main(int argc, char* argv[])
{
    func(1, 2);
    return 0;
}

//输出结果
//2
//1
//var1=1,var2=2
