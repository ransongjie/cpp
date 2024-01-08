#include <iostream>
#include <vector>
using namespace std;

/*
https://leetcode.cn/problems/subsets/
子集
幂集
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIdx)
    {
        // 取每个结点
        ans.push_back(path);
        if (startIdx >= nums.size())
        {
            return;
        }
        for (int i = startIdx; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        ans.clear();
        path.clear();
        backtracking(nums, 0);
        return ans;
    }
};