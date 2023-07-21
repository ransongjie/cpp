#include <iostream>
#include <cstring>
using namespace std;

typedef struct Student
{
   int   id;
   char  name[50];
}Student;

int main(){
    Student stu;
    stu.id=1;
    strcpy( stu.name, "xcrj");
    cout<<stu.id<<endl;
    cout<<stu.name<<endl;
}
