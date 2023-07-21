#include <iostream>
using namespace std;
/**
 * C++有哪几种构造函数
 * 默认构造函数（无参数），完成对象的初始化工作
 * 初始化构造函数（有参数），完成对象的初始化工作
 * 拷贝构造函数，复制构造函数用于复制本类的对象
 * 转换构造函数，隐式转换为本类对象
 *
 * 移动构造函数（move和右值引用）
 * 委托构造函数
 */
class Student{
public:

    //默认构造函数，没有参数
    Student(){
        this->age = 20;
        this->num = 1000;
    };

    //初始化构造函数，有参数和参数列表
    Student(int a, int n):age(a), num(n){};

    //拷贝构造函数，这里与编译器生成的一致
    Student(const Student& s){
        this->age = s.age;
        this->num = s.num;
    };

    //转换构造函数,形参是其他类型变量，且只有一个形参
    Student(int r){
        this->age = r;
        this->num = 1002;
    };

    ~Student(){}
public:
    int age;
    int num;
};

int main(){
    Student s1;
    Student s2(18,1001);
    int a = 10;
    Student s3(a);
    Student s4(s3);

    printf("s1 age:%d, num:%d\n", s1.age, s1.num);
    printf("s2 age:%d, num:%d\n", s2.age, s2.num);
    printf("s3 age:%d, num:%d\n", s3.age, s3.num);
    printf("s2 age:%d, num:%d\n", s4.age, s4.num);
    return 0;
}
//运行结果
//s1 age:20, num:1000
//s2 age:18, num:1001
//s3 age:10, num:1002
//s2 age:10, num:1002