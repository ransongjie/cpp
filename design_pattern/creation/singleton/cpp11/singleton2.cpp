#include <iostream>
#include <memory>
#include <mutex>
/*
g++ singleton2.cpp -pthread
std::call_once 实现单例
返回智能指针
*/
class Singleton
{
public:
    // 声明静态方法
    // 返回智能指针
    static std::shared_ptr<Singleton> getInstance();
    ~Singleton()
    {
        std::cout << "析构函数" << std::endl;
    }

private:
    Singleton()
    {
        std::cout << "构造函数" << std::endl;
    }
};

// 智能指针
static std::shared_ptr<Singleton> sp = nullptr;
static std::once_flag oflag;

// 定义静态方法
std::shared_ptr<Singleton> Singleton::getInstance()
{
    std::call_once(oflag, [&](){ sp = std::shared_ptr<Singleton>(new Singleton()); });
    return sp;
}

int main()
{
    // 运行1次
    std::shared_ptr<Singleton> s1 = Singleton::getInstance();

    // 运行100 000次
    for (int i = 0; i < 100000; i++)
    {
        std::shared_ptr<Singleton> s2 = Singleton::getInstance();
        if (s2 != s1)
        {
            std::cout << "error" << std::endl;
            break;
        }
    }

    return 0;
}