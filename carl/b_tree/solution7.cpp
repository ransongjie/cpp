#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/symmetric-tree/
对称二叉树
同时递归1棵树的左右孩子
*/
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return false;
        return compare(root->left, root->right);
    }

    /**
     * 递归三部曲：
     * 1. 确定入参和返回值
     * 2. 确定终止条件
     * 3. 确定单层逻辑
     */
    bool compare(TreeNode *left, TreeNode *right)
    {
        // 终止条件
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL && right != NULL)
            return false;
        if (left != NULL && right == NULL)
            return false;
        // 单层逻辑
        bool out = compare(left->left, right->right);
        bool in = compare(left->right, right->left);
        return (left->val == right->val) && out && in;
    }
};