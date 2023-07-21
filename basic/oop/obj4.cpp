#include <iostream>
using namespace std;
/**
 * 多态
 */

class Apple{
    public:
        string name;
        Apple(string name){
            this->name=name;
        }
        //必须=0，纯虚函数
        //虚函数，本质 动态链接 运行时绑定
        virtual string getName()=0;
};
class FujiApple:public Apple{
    public:
        int code;
        //调用父类构造函数，自己的私有变量
        FujiApple(string name,int code):Apple(name),code(code){}
        string getName() override{
            return this->name;
        }
};
class YantaiApple:public Apple{
    public:
        int code;
        YantaiApple(string name,int code):Apple(name),code(code){}
        string getName() override{
            return this->name;
        }
};

int main(){
    Apple* apple=new FujiApple("富士苹果",100);
    Apple* apple2=new YantaiApple("烟台苹果",200);
    cout<<apple->getName()<<endl;
    cout<<apple2->getName()<<endl;
    //手动调用析构函数
    delete apple;
    delete apple2;
}