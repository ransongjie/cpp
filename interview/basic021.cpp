#include <utility>
#include <iostream>
using namespace std;

/**
 * 零拷贝
 * 构造函数
 * 拷贝构造函数
 * 转移构造函数
 */

class MyClass {
public:
    //构造函数
    MyClass() { std::cout << "Default constructor\n"; }
    //拷贝构造函数
    MyClass(const MyClass& other) { std::cout << "Copy constructor\n"; }
    //转移构造函数
    MyClass(MyClass&& other) { std::cout << "Move constructor\n"; }
};

int main() {
    MyClass obj1;
    //std::move(obj1) obj1左值引用>右值引用 赋值时调用转移构造函数
    MyClass obj2 = std::move(obj1);
    return 0;
}