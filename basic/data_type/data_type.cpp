#include <iostream>
#include <ctime>//日期时间
using namespace std;

//预定义常量
#define cb 10

/*
 变量，常量
 类型分类, 类型范围, 字面量, 默认值, 类型转换
 ！精度，溢出
 */
int main(){
    //整数
    int a=10;//4 byte, 默认signed
    signed int sa=-10;
    unsigned int ua=10;// 4 byte
    short int b=10;//2 byte
    signed short int sb=10;
    unsigned short int ub=10;
    long int c=10;//8 byte
    signed long int sc=10;
    unsigned long int uc=10;

    //浮点数
    float d=20.0;//4 byte
    double dd=20.0;//8 byte
    long double ld=20.0;//16 byte

    //布尔
    bool e=false;//1 byte, 0=false, 1=true

    //字符
    char f='x';
    signed char sf='x';
    unsigned char uf='x';

    //常量
    const int ca=10;

    //数组
    int gs0[3];//空间已分配，未赋值
    int gs1[3]={};//全部赋值为0
    int gs3[3]={0};//全部赋值为0
    int gs2[3]={1,2,3};//逐个赋值
    cout<<gs1[2]<<endl;

    //字符串
    //c++
    string str1="xcrj";
    cout<<str1.size()<<endl;//输出4
    //c
    char str2[] = "xcrj";
    cout<<str2<<endl;
    char str3[] = {'x','c','r','j','\0'};//必须加上\0
    cout<<str3<<endl;

    //日期时间
    time_t now=time(0);//格林尼治时间, 格林尼治标准时间1970年1月1日00:00:00至当前时刻所流逝的秒数。
    char* cnow=ctime(&now);
    cout<<cnow<<endl;
    tm* ltm=localtime(&now);
    cout<<1900+ltm->tm_year
        <<"-"<<1+ltm->tm_mon
        <<"-"<<ltm->tm_mday
        <<" "<<ltm->tm_hour
        <<":"<<ltm->tm_min
        <<":"<<ltm->tm_sec<<endl;//2023-3-23 23:14:16
    
    time_t nowtime = time(NULL); //获取日历时间   
    char tmp[64];   
    strftime(tmp,sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&nowtime));
    string str=tmp;
    cout<<str.c_str()<<endl; //2023-03-23 23:20:49

    //类型别名
    typedef int xcrj;
    xcrj xc=10;
    //枚举类型
    enum direction{east,south,west,north} dn;
    dn=east;
}