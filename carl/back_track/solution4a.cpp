#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://leetcode.cn/problems/combination-sum/
组合总和

组合总和III的区别是：
本题可以无限重复使用相同数字，但是有总和的限制，所以间接的也是有个数的限制。

剪枝

sort: <algorithm>
*/

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int sum, int startIdx)
    {
        // if (sum > target) // 走到这里，已经进入了下一层
        // {
        //     return;
        // }
        if (sum == target)
        {
            ans.push_back(path);
            return;
        }
        // sum + candidates[i] > target, 已排序, 本结点后续元素无需再遍历。不满足也不用进入下一层
        for (int i = startIdx; i < candidates.size() && sum + candidates[i] <= target; i++)
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
        sort(candidates.begin(), candidates.end()); // 排序
        backtracking(candidates, target, 0, 0);
        return ans;
    }
};