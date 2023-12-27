#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/combination-sum-iii/
组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
剪枝
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIdx)
    {
        if (sum > targetSum)
            return;
        if (path.size() == k)
        {
            if (sum == targetSum)
                ans.push_back(path);
            return;
        }

        for (int i = startIdx; i <= 9 - (k - path.size()) + 1; i++) // 1~9个整数
        {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        ans.clear();
        path.clear();
        backtracking(n, k, 0, 1); // targetSum=n, sum=0, 从1开始
        return ans;
    }
};