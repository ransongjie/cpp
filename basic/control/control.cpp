#include <iostream>
using namespace std;

//判断（if, switch），循环(for, while, do while)
int main(){
    //判断 if
    int a = 10;
    if (a > 10) {
        cout<<("a>10")<<endl;
    } else if (a == 10) {
        cout<<("a=10")<<endl;
    } else {
        cout<<("a<10")<<endl;
    }

    //判断 switch
    /// 无case穿透
    int e = 1;
    switch (e) {
        case 1:
            cout<<("e = 1")<<endl;
            break;
        case 2:
            cout<<("e = 2")<<endl;
            break;
        case 3:
            cout<<("e = 3")<<endl;
            break;
        default:
            cout<<("e=?")<<endl;
    }
    /// 有case穿透，default也会被穿透
    cout<<("有case穿透")<<endl;
    switch (e) {
        case 1:
            cout<<("e = 1")<<endl;
        case 2:
            cout<<("e = 2")<<endl;
        case 3:
            cout<<("e = 3")<<endl;
        default:
            cout<<("e=?")<<endl;
    }    

    //循环 for
    /// for-index
    int n=3;
    int as[] = { 1, 2, 3 };
    for (int i = 0; i < n; i++) {
        cout<<(as[i])<<endl;
    }
    /// for-range c++ 11
    for(int &a:as){
        cout<<a<<endl;
    }

    //循环 while
    int n1=0;
    int bs[] = { 1, 2, 3 };
    while(n1<3){
        cout<<bs[n1]<<endl;
        while(true){
            break;//跳出当前循环
        }
        //break后 继续执行下面的代码
        cout<<("break 后的代码")<<endl;
        n1++;
    }

    //循环 do while
    int d = 1;
    do {
        d++;
        ///不执行continue后面的语句，跳到下一次循环
        if(d>2) continue;
        d<<=1;
    } while (d < 10);
    cout<<(d)<<endl;
}