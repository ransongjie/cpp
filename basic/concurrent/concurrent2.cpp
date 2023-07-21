#include <iostream>
#include <thread>
using namespace std;

void func(int Z)
{
    for (int i = 0; i < Z; i++)
    {
        cout << "线程使用函数指针作为入参\n";
    }
}
class claz
{
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "线程使用函数对象作为入参\n";
    }
};

int main()
{
    cout << "线程 1 、2 、3 独立运行"<< endl;

    // 入参，函数指针
    thread th1(func, 3);

    // 入参，对象
    thread th2(claz(), 3);

    // 定义 Lambda 表达式
    auto lambdaf = [](int x)
    {
        for (int i = 0; i < x; i++)
            cout << "线程使用 lambda 表达式作为入参\n";
    };

    // 入参，lambda表达式
    thread th3(lambdaf, 3);

    // 等待线程 t1 完成
    th1.join();
    // 等待线程 t2 完成
    th2.join();
    // 等待线程 t3 完成
    th3.join();

    return 0;
}