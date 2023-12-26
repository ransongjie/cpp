#include <iostream>
using namespace std;
/**
 * try catch throw
 * 自定义异常 struct MyException:public exception
 *
 */
void test();
void test1();
void test2();

int main() {
    test();
    test1();
    test2();
}

//try catch throw
void test(){
   try {
      int num1=0;
      if (num1 == 0) {
         throw "Divide by zero error!";
      }
   } catch(const char* msg) {
      cerr << msg << endl;
   }
}

//自定义异常 std::exception
struct MyException:public exception{
    /*
    https://learn.microsoft.com/zh-cn/cpp/cpp/exception-specifications-throw-cpp?view=msvc-170
    建议只使用noexcept规范
    c++11，引入noexcept，放到函数()后
        函数不会抛出任何异常，noexcept(true) 或 noexcept
        函数可能抛出异常，noexcept(false)
        函数在noexcept(false)的情况下抛出了异常，则程序将调用std::terminate()，终止程序的执行
    c++11-，
        void fun() throw(); //表示fun函数不允许抛出任何异常，即fun函数是异常安全的。
        void fun() throw(...); //表示fun函数可以抛出任何形式的异常。
        void fun() throw(exceptionType); //表示fun函数只能抛出exceptionType类型的异常。
        void fun() throw(int); // 表示只抛出int类型异常
        void fun() throw(int，char); // 表示抛出in，char类型异常
    */
    const char* what () const noexcept
    {
        return "C++ My exception";
    }
};

void test1(){
  try
  {
    throw MyException();
  }catch(MyException& e)
  {
    std::cout << "MyException caught" << std::endl;
    std::cout << e.what() << std::endl;
  }catch(std::exception& e)
  {
    //其他的错误
  }
}

class MyException2 : public exception {
private:
    string message_;
public:
    MyException2(const string& message) : message_(message) {}
    const char* what() const throw() {
        return message_.c_str();
    }
};

void test2() {
    try {
        throw MyException2("An error occurred in myFunc()");
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
}
