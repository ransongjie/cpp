#include <iostream>
using namespace std;
/*
g++ singleton.cpp
*/
class Singleton
{
private:
    // 单例
    static Singleton *instance;

    /*私有化CPP空类默认生成的函数*/
    // 默认构造
    Singleton()
    {
        cout << "构造函数" << endl;
    }
    // 析构函数，也可以设为public，自己手动写deleteInstance函数内容
    ~Singleton()
    {
        cout << "析构函数" << endl;
    }
    // 拷贝构造, =delete了，设置为公共的也可以
    Singleton(const Singleton &singleton)=delete;
    // 赋值构造, =delete了，设置为公共的也可以
    Singleton &operator=(const Singleton &singleton)=delete;

public:
    // 获取单例
    static Singleton *getInstance()
    {
        return instance;
    }
    // 释放单例
    static void deleteInstance()
    {
        if (instance)
        {
            delete instance; // delete会判断instance是否为nullptr
            instance = nullptr;
        }
    }
};
// static成员变量先于对象存在，所以static成员变量要在类外初始化
// 静态全局变量、静态局部变量、静态成员变量
// 静态成员变量在第1次运行到的时候线程安全的初始化1次
// nothrow new失败返回NULL
Singleton *Singleton::instance = new (std::nothrow) Singleton();

int main()
{
    // 运行1次
    Singleton *s1 = Singleton::getInstance();

    // 运行100 000次
    Singleton *s2 = nullptr;
    for (int i = 0; i < 100000; i++)
    {
        s2 = Singleton::getInstance();
        if (s2 != s1)
        {
            cout << "error" << endl;
            break;
        }
    }

    s2->deleteInstance();
    s1->deleteInstance();

    return 0;
}
