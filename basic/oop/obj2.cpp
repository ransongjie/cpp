#include <iostream>
using namespace std;
/**
 * 继承 多继承 private protected public继承
 * 访问控制 private protected public
 */
class Apple{
    public:
        string name;
        void setName(string name){
            this->name=name;
        }
        string getName(){
            return this->name;
        }
};

//继承
class FujiApple:public Apple{
};

int main(){
    FujiApple fujiApple;
    fujiApple.setName("富士苹果");
    cout<<fujiApple.getName()<<endl;
}