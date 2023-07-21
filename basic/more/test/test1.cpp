#include <iostream>
#include <vector>
using namespace std;
//
// Created by xcrj on 2023/7/15.
//
int main(){
    std::vector<int> v{1,2,3,5};
    v.insert(v.end(), 2, 4);//{1,4,2,3,5}
    for(auto &i:v){
        cout<<i<<endl;
    }
}