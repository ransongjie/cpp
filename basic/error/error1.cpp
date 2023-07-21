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

//自定义异常 std:exception
struct MyException:public exception{
    //const throw () 不会修改对象的状态且不会抛出任何异常
    //C++11中引入了noexcept关键字，throw()弃用
    //const char* what () const throw ()
    //noexcept 表示函数不会抛出任何异常
    //noexcept(true) 表示函数不会抛出任何异常
    //noexcept(false) 表示函数可能会抛出异常
    //如果函数在noexcept(false)的情况下抛出了异常，则程序将调用std::terminate()，终止程序的执行。
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
public:
    MyException2(const string& message) : message_(message) {}
    const char* what() const throw() {
        return message_.c_str();
    }
private:
    string message_;
};

void test2() {
    try {
        throw MyException2("An error occurred in myFunc()");
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }
}
