#include <iostream>

using namespace std;

/**
 * explicit
 * 修饰构造函数，只能显式转换类型转换
 */
#include <iostream>

class MyClass {
public:
    //explicit
    explicit MyClass(int n) : num(n) {}

    int getNum() const { return num; }

private:
    int num;
};

void printNum(const MyClass &obj) {
    std::cout << obj.getNum() << std::endl;
}

int main() {
    MyClass obj1(10); // 直接调用构造函数
    printNum(obj1); // 调用printNum函数，传入MyClass对象

    //下面的代码会导致编译错误，因为构造函数是explicit的，不能进行隐式类型转换
    MyClass obj2 = 20;
    printNum(obj2);

    MyClass obj3 = MyClass(30); // 显式调用构造函数
    printNum(obj3);

    return 0;
}