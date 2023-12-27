#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/combination-sum-iii/
组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

数组candidates无重复元素
结果组合内，元素不同，用i+1解决
结果组合间，解集不能包含重复的组合，用回溯解决，叶子结点
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int startIdx)
    {
        if (path.size() == k)
        {
            if (sum == targetSum)
                ans.push_back(path);
            return;
        }

        for (int i = startIdx; i <= 9; i++) // 1~9个整数
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