#include <iostream>
#include <vector>
using namespace std;
/**
 * 泛型：模板
 */
void test();
void test1();

//函数模板
template <typename T>
T add(T a, T b) {
    return a + b;
}

void test(){
    int a = 2, b = 3;
    double c = 2.5, d = 3.5;
    cout << add(a, b) << endl;    // 输出 5
    cout << add(c, d) << endl;    // 输出 6
}

//类模板
template <class T>
class Stack { 
  private: 
    //元素 
    vector<T> elems;     
 
  public: 
    void push (T const& elem){// 等价于const T& elem
        //追加传入元素的副本
        elems.push_back(elem); 
    } 
}; 

void test1(){
    //int类型的栈 
    Stack<int> intStack;
    //操作int类型的栈 
    intStack.push(7);
    //string类型的栈 
    Stack<string> stringStack;
    //操作string类型的栈
    stringStack.push("hello");
}

int main() {
    test();
    test1();
}