#include <iostream>
#include <mutex>
/*
加锁的懒汉式实现
DCL (Double Check Lock)
*/

class Singleton
{
public:
    static Singleton *getInstance();
    static void deleteInstance();

private:
    Singleton()
    {
        std::cout << "构造函数" << std::endl;
    }
    ~Singleton()
    {
        std::cout << "析构函数" << std::endl;
    }
    Singleton(const Singleton &singleton) = delete;
    Singleton &operator=(const Singleton &singleton) = delete;

private:
    static Singleton *instance;
    static std::mutex mtx;
};

Singleton *Singleton::instance = nullptr;
std::mutex Singleton::mtx;

// 注意：不能返回指针的引用，否则存在外部被修改的风险！todo
Singleton *Singleton::getInstance()
{
    // DCL
    if (instance == nullptr)
    {
        std::unique_lock<std::mutex> lock(mtx); // 加锁
        if (instance == nullptr)
        {
            volatile auto temp = new (std::nothrow) Singleton();
            instance = temp;
        }
    }

    return instance;
}

void Singleton::deleteInstance()
{
    std::unique_lock<std::mutex> lock(mtx); // 加锁
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
}

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
            std::cout << "error" << std::endl;
            break;
        }
    }

    s2->deleteInstance();
    s1->deleteInstance();

    return 0;
}