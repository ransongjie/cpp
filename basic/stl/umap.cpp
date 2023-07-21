#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    //HashMap, ordered_map<int,int> mp TreeMap
    unordered_map<int,int> mp;
    mp[1]++;//默认为0
    cout<<mp[1]<<endl;
}