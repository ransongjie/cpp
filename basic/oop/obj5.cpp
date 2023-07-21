#include <iostream>
using namespace std;

/**
 * 抽象类：包含至少1个纯虚函数
 * 接口（特殊的抽象类）：只包含纯虚函数和公共静态常量
 */

class Shape{
    public:
        //纯虚函数
        virtual string getName()=0;

};

class Circle:public Shape{
    private:
        string name;
    public:
        Circle(string name):name(name){}
        //实现
        string getName() {
            return this->name;
        }
};

int main(){
    Circle* circle=new Circle("圆形");
    cout<<circle->getName()<<endl;
    delete circle;
}