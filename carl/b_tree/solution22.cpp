#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
二叉搜索树的最小绝对差
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
*/
class Solution
{
private:
    int minV = INT_MAX;
    TreeNode *pre = NULL;
    void traversal(TreeNode *cur)
    {
        // 递归出口
        if (cur == NULL)
            return;
        // 当前层逻辑
        traversal(cur->left);
        if (pre != NULL)
        {
            // 二叉搜索树是有序的，相邻结点一定产生最小值
            minV = min(minV, cur->val - pre->val);
        }
        pre = cur;
        traversal(cur->right);
    }

public:
    int getMinimumDifference(TreeNode *root)
    {
        traversal(root);
        return minV;
    }
};