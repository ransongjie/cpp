#include <iostream>
#include <memory>
#include <mutex>

/*
返回智能指针
DCL
*/
class Singleton
{
public:
    static std::shared_ptr<Singleton> getInstance();
    // 析构函数 public，智能指针负责析构
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

static std::shared_ptr<Singleton> sp = nullptr;
static std::mutex mtx;

std::shared_ptr<Singleton> Singleton::getInstance()
{
    // DCL
    if (sp == nullptr)
    {
        std::unique_lock<std::mutex> lock(mtx);
        if (sp == nullptr)
        {
            /*
            volatile 可见性 有序性
            volatile关键字用于指示编译器不要对变量进行优化，
            以确保每次访问该变量时都从内存中读取最新的值。
            然而，对于智能指针的赋值操作，这种使用是不正确的。

            智能指针的赋值操作是一个需要严格执行的操作，涉及引用计数的增减和资源的释放等。
            volatile关键字的使用可能会导致编译器对智能指针的赋值操作进行优化，
            从而破坏了智能指针的内部逻辑，可能导致内存泄漏或其他错误。
            */
            /*
            为什么先赋值给temp再给singleton?
            在并发场景下可能会出现问题。
            singleton 对象在初始化的时候实际上是分三步的：
            1. 先申请一块内存
            2. 再调用构造函数进行初始化
            3. 将内存地址赋值给 singleton
            但是上述操作在不同编译器上表现可能是不一样的，
            可能先将内存地址赋值给 singleton ，再调用构造函数进行初始化。
            那在并发场景下，线程拿到的 singleton 可能是还未构造完成的单例对象，在使用时可能出现问题。
            先赋值给 temp 在赋值给 singleton ，可以保证返回的单例对象一定是初始化完成的。
            */
            // volatile auto temp = std::shared_ptr<Singleton>(new Singleton());
            auto temp = std::shared_ptr<Singleton>(new Singleton());
            sp = temp;
        }
    }
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