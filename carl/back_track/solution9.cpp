#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://leetcode.cn/problems/subsets-ii/
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
        ans.push_back(path);
        if (startIdx >= nums.size())
        {
            return;
        }
        for (int i = startIdx; i < nums.size(); i++)
        {
            // i>startIdx只限制同层不能重复
            if(i>startIdx&&nums[i]==nums[i-1]){
                continue;
            }
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
        sort(nums.begin(),nums.end());
        backtracking(nums, 0);
        return ans;
    }
};