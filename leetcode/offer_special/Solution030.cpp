#include <iostream>
#include <unordered_map>
using namespace std;

class Solution030
{
public:
    // 内部类
    class RandomizedSet
    {
    private:
        unordered_map<int, int> idxVal;
        unordered_map<int, int> valIdx;
        int size;

    public:
        RandomizedSet()
        {
            size = 0;
        }
        bool insert(int val)
        {
            if (valIdx.find(val) != valIdx.end())
            { //
                return false;
            }
            // valIdx.insert(val, size); //编译错误
            valIdx[val] = size; //
            idxVal[size++] = val;
            return true;
        }
        bool remove(int val)
        {
            if (valIdx.find(val) == valIdx.end())
            {
                return false;
            }
            int delIdx = valIdx[val]; //
            int lstVal = idxVal[--size];
            valIdx[lstVal] = delIdx;
            idxVal[delIdx] = lstVal;
            valIdx.erase(val); //
            idxVal.erase(size);
            return true;
        }
        int getRandom()
        {
            int idx = rand() % size;
            return idxVal[idx];
        }
    };
};