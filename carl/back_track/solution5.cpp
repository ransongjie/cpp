#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://leetcode.cn/problems/combination-sum-ii/
组合总和II

每个数字在每个组合中只能使用一次
难点：数组candidates有重复元素，但还不能有重复的结果组合

数组candidates有重复元素
结果组合内，元素可以相同，单个叶子结点内的元素可以重复
结果组合间，解集不能包含重复的组合，不同叶子结点不可重复
*/
class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int startIdx)
    {
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        for (int i = startIdx; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            // 同层结点不可相同，前面已经处理了相同数字candidates[i - 1]
            if (i > startIdx && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        ans.clear();
        path.clear();
        // 排序，将相同数字放到一起
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};