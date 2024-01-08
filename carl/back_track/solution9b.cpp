#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
https://leetcode.cn/problems/subsets-ii/
子集
幂集
去重操作不同
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIdx)
    {
        ans.push_back(path);
        unordered_set<int> uset; // 同层不能重复，下层将创建新的uset
        if (startIdx >= nums.size())
        {
            return;
        }
        for (int i = startIdx; i < nums.size(); i++)
        {
            // 重复则跳过
            if (uset.find(nums[i]) != uset.end())
            {
                continue;
            }
            uset.insert(nums[i]); //
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return ans;
    }
};