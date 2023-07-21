#include <iostream>
using namespace std;

#include <iostream>

#include <iostream>
/**
 * 不同于java的内部类
 * c++内部类不依赖与外部类而存在
 * c++内部类只是拥有外部类访问权限的一般类 
 * c++没有静态内部类
 */
class Outer {
private:
    string name;
public:
    void outerMethod() {
        //编译不通过，外部类不能访问内部类的成员
        // Inner inner;
        // inner.innerMethod();
        cout << "Hello from outer" << endl;
    }

    class Inner {
    public:
        void innerMethod() {
            Outer outer;
            outer.name="xcrj";
            cout << "Hello from inner: "+outer.name << endl;
        }
    };
};

int main() {
    // Outer outer;
    // outer.outerMethod();

    Outer::Inner inner;
    inner.innerMethod();

    return 0;
}