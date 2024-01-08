#include <iostream>
#include <vector>
using namespace std;
/*
https://leetcode.cn/problems/permutations/
全排列
入参不包含重复元素
*/
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, vector<bool> &used)
    {
        // 收集叶子结点
        if (path.size() == nums.size())
        {
            ans.push_back(path);
        }
        // 排列问题不从startIdx开始，每次都从0开始
        for (int i = 0; i < nums.size(); i++)
        {
            // nums[i]已经使用过，跳过
            if (used[i])
            {
                continue;
            }
            // 使用第nums[i]个数字
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        vector<bool> used(nums.size(), false); //
        backtracking(nums, used);
        return ans;
    }
};
