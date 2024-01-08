#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/non-decreasing-subsequences/description/
非递减子序列
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。
利用数字去重，已知 题目数值范围[-100, 100]
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIdx)
    {
        // 递增子序列长度>1，不仅取叶子结点，取每个结点
        if (path.size() > 1)
        {
            ans.push_back(path);
        }
        // 使用数组去重
        int used[201] = {0};
        for (int i = startIdx; i < nums.size(); i++)
        {
            // 已经处理过，同层不可重复
            if (used[nums[i] + 100] == 1)
            {
                continue;
            }
            // 非递增
            if (!path.empty() && nums[i] < path.back())
            {
                continue;
            }
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        backtracking(nums, 0);
        return ans;
    }
};