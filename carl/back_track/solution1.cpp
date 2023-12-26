#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/combinations/
组合
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(int n, int k, int startIdx)
    {
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIdx; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        ans.clear();
        path.clear();
        backtracking(n, k, 1); // 从1开始
        return ans;
    }
};