#include <iostream>
#include <string>
using namespace std;

void test1();
void test2();
void test3();
/*
 类型提升，类型降低
 */
int main()
{
    test1();
    test2();
    test3();

    return 0;
}

void test1()
{
    // 整数 整数 相互转换
    int a = 10;
    long int la = a;

    long int lb = 20;
    int b = lb;

    // 浮点数 浮点数 相互转换
    float c = 10.2;
    double dc = c;
    cout << dc << endl;

    double d = 20.3;
    float fd = d;
    cout << fd << endl;

    // 整数 浮点数 相互转换
    int e = 10;
    float fe = e;
    cout << fe << endl;

    float f = 23.3;
    int fi = int(f); // 强制类型转换 也称 cast运算符
    cout << fi << endl;
}

/*
string to long int
*/
void test2()
{
    // converting decimal number.
    string dec_num = "9876543210";
    cout << "dec_num=" << stol(dec_num, nullptr, 10) << "\n";
    // converting hexadecimal number.
    string hex_num = "FFFFFF";
    cout << "hex_num=" << stol(hex_num, nullptr, 16) << "\n";
    // converting binary number.
    string binary_num = "1111111";
    cout << "binary_num=" << stol(binary_num, nullptr, 2) << "n";
}

/*
string to long long int
*/
void test3()
{
    // converting decimal number.
    string dec_num = "9876543210";
    cout << "dec_num=" << stoll(dec_num, nullptr, 10) << "\n";
    // converting hexadecimal number.
    string hex_num = "FFFFFF";
    cout << "hex_num=" << stoll(hex_num, nullptr, 16) << "\n";
    // converting binary number.
    string binary_num = "1111111";
    cout << "binary_num=" << stoll(binary_num, nullptr, 2) << "n";
}