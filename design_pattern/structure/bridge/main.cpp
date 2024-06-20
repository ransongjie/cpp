#include <iostream>
#include "os.h"
#include "phone.h"

// 宏函数
#ifndef DELETE_OBJECT
#define DELETE_OBJECT(p) \
    {                    \
        if (NULL != (p)) \
        {                \
            delete (p);  \
            (p) = NULL;  \
        }                \
    }
#endif
/*
g++ main.cpp
苹果手机和Nokia手机可以使用不同的操作系统
苹果收购Nokia手机后，能够统一为IOS操作系统
*/
int main()
{
    OS *ios511 = new IOS511();           // 创建一个操作系统
    Phone *iPhone4 = new iPhone(ios511); // 应用到该手机上
    iPhone4->getOS();

    OS *saiBian110 = new SaiBian110();
    Phone *nokia1 = new Nokia(saiBian110);
    nokia1->getOS();

    DELETE_OBJECT(ios511);
    DELETE_OBJECT(iPhone4);
    DELETE_OBJECT(saiBian110);
    DELETE_OBJECT(iPhone4);

    return 0;
}