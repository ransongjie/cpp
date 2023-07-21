#include<iostream>
using namespace std;
//赋值, 算数, 关系, 逻辑, 位, 三元

class Student{
    public:
        string name;
        string code;
        int age;
};

int main(){
    //赋值, =, +=, -= ...
    int aint=10;
    int bint=20;
    bint+=1;
    bint-=1;

    //算数，+,-,*,/,%,++,--
    cout<<aint+bint<<endl;
    cout<<aint-bint<<endl;
    cout<<aint*bint<<endl;
    cout<<aint/bint<<endl;
    cout<<aint%bint<<endl;
    cout<<aint++<<endl;
    cout<<aint--<<endl;
    cout<<++aint<<endl;
    cout<<--aint<<endl;

    //关系, ==, !=, >, <, >=, <=
    cout<<(aint==bint)<<endl;
    cout<<(aint!=bint)<<endl;
    cout<<(aint>bint)<<endl;
    cout<<(aint<bint)<<endl;
    cout<<(aint>=bint)<<endl;
    cout<<(aint<=bint)<<endl;

    //逻辑, &&, ||, !
    bool abool=true;
    bool bbool=false;
    cout<<(abool&&bbool)<<endl;
    cout<<(abool||bbool)<<endl;
    cout<<(!abool)<<endl;

    //位, &, |, ~, ^, <<, >>
    int cint =10;
    int dint=20;
    cout<<(cint&dint)<<endl;
    cout<<(cint|dint)<<endl;
    cout<<(~cint)<<endl;//按位取反
    cout<<(cint^dint)<<endl;
    cout<<(cint<<1)<<endl;//不改变cint原值
    cout<<(cint)<<endl;
    cout<<(cint>>1)<<endl;//不改变cint原值
    cout<<(cint)<<endl;

    //三目运算符
    int eint=true?10:20;
    cout<<eint<<endl;

    //byte size
    int fint=10;
    cout<<sizeof(fint)<<endl;// 4

    //指针
    int gint=10;
    int* pgint=&gint;// 取址运算符
    cout<<*pgint<<endl;// 取值运算符

    //引用 别名
    int hint=19;
    int &fhint=hint;
    cout<<fhint<<endl;

    //类相关运算符 . ->
    Student stu;
    stu.age=18;
    cout<<stu.age<<endl;// 类.属性
    Student* pstu=&stu;
    cout<<pstu->age<<endl;// 类指针->属性
}