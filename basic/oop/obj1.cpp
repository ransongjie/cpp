#include <iostream>
using namespace std;
/*
创建对象
*/
class Teacher{
    public:
        int id;
        string name;
        //构造函数声明
        Teacher(int id,string name);
        //析构函数声明
        ~Teacher();
        //成员函数声明
        string getName();
};
//构造函数
Teacher::Teacher(int id,string name)
{
    this->id=id;
    this->name=name;
}
//析构函数
Teacher::~Teacher()
{
    cout<<"对象被删除"<<endl;
}
//成员函数
string Teacher::getName()
{
    return name;
}

int main(){
    Teacher teacher(1,"xcrj");
    cout<<teacher.id<<endl;
    cout<<teacher.name<<endl;
}
