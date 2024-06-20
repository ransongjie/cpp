#include <iostream>
/*
g++ singleton.cpp
cpp 11，经典，静态局部变量的懒汉单例
*/
class Singleton
{
    // 公共 析构函数 拷贝构造 赋值构造
public:
    ~Singleton()
    {
        std::cout << "析构函数" << std::endl;
    };
    //=delete 删除该函数
    Singleton(const Singleton &singleton) = delete;
    Singleton &operator=(const Singleton &singleton) = delete;
    // 出参 引用传递
    static Singleton &getInstance()
    {
        // static局部变量在第1次运行到的时候线程安全的初始化1次
        // std::cout << "函数" << std::endl;
        static Singleton instance;
        return instance;
    }
    // 私有 构造函数
private:
    Singleton()
    {
        std::cout << "构造函数" << std::endl;
    }
};

int main()
{
    // 运行1次
    Singleton &s1 = Singleton::getInstance();

    // 运行100 000次
    for (int i = 0; i < 100000; i++)
    {
        Singleton &s2 = Singleton::getInstance();
        if (&s2 != &s1)
        {
            std::cout << "error" << std::endl;
            break;
        }
    }

    return 0;
}