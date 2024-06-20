#include "./include/proxy.h"
// g++ *.cpp -I ./include -std=c++11
// 静态代理
int main()
{
    BrideGroom brideGroom; // 栈上分配
    WedCompany *wedCompany = new WedCompany(brideGroom);
    wedCompany->wed();

    delete wedCompany;
    wedCompany = nullptr;
    return 0;
}