#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/maximum-binary-tree/
最大二叉树
创建一个根节点，其值为 nums 中的最大值
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
*/
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        // 只有1个元素，结束递归
        TreeNode *root = new TreeNode();
        if (nums.size() == 1)
        {
            root->val = nums[0];
            return root;
        }

        // 递归中，寻找最大元素及其索引
        int maxV = INT_MIN, idx;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxV < nums[i])
            {
                maxV = nums[i];
                idx = i;
            }
        }
        root->val = maxV; // 最大值

        // 分割左右子树
        if (idx > 0)
        {
            vector<int> left(nums.begin(), nums.begin() + idx);
            root->left = constructMaximumBinaryTree(left);
        }
        if (idx < nums.size() - 1)
        {
            vector<int> right(nums.begin() + idx + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};