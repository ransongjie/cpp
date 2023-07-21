#include <iostream>
#include <string>

using namespace std;
//
// Created by xcrj on 2023/7/15.
//
/**
* str遍历的三种方式
*/
//运算符遍历
void print1(string s) {
    for (size_t i = 0; i < s.size(); i++) {
        cout << s[i] << " ";//支持下标访问
        //等价于cout << s.operator[](i) << " ";
    }
    cout << endl;
}

//新式for遍历 cpp11
void print2(string s) {
    for (auto e: s)
    {
        cout << e << " ";
    }
    cout << endl;
}

//正向迭代器遍历
void print3(string s) {
    //迭代器=指针
    string::iterator sit = s.begin();
    while (sit != s.end()) {
        cout << *sit << " ";
        sit++;
    }
    cout << endl;
}

//反向迭代器遍历
void print4(string s) {
    string::reverse_iterator sit = s.rbegin();
    while (sit != s.rend()) {
        cout << *sit << " ";
        sit++;
    }
    cout << endl;
}

//普通正反向迭代器，可以改变数据，使用常量正反向迭代器
//const正向迭代器
void print5(const string &s) {
    string::const_iterator sit = s.begin();
    while (sit != s.end()) {
//        *sit = '1';//不能修改数据, sit是const char (*p)
        cout << *sit << " ";
        sit++;
    }
    cout << endl;
}

//const反向迭代器
void print6(const string &s) {
    string::const_reverse_iterator sit = s.rbegin();
    while (sit != s.rend()) {
        //*sit = '1';不能修改数据
        cout << *sit << " ";
        sit++;
    }
    cout << endl;
}

int main() {
    print1("xcrj");
    print2("xcrj");
    print3("xcrj");
    print4("xcrj");
    print5("xcrj");
    print6("xcrj");
}