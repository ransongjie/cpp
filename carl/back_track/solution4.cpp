#include <iostream>
#include <vector>
using namespace std;

/*
https://leetcode.cn/problems/combination-sum/
组合总和
无重复元素的数组 candidates
结果，可以无限重复使用相同数字

数组candidates无重复元素
结果组合内，元素可以相同，i
结果组合间，解集不能包含重复的组合，回溯解决，叶子结点
*/

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int sum, int startIdx)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIdx; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i); // i没有+1，因为同1个数字可以重复选取
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};