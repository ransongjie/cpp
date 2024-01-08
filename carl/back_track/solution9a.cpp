#include <iostream>
#include <vector>
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
    void backtracking(vector<int> &nums, int startIdx, vector<bool> used)
    {
        ans.push_back(path);
        if (startIdx >= nums.size())
        {
            return;
        }
        for (int i = startIdx; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        vector<bool> used(nums.size(), false); // 默认值false
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return ans;
    }
};