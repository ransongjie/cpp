#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/trim-a-binary-search-tree/
修剪二叉搜索树
*/
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val < low)
        {
            // 继续递归直到满足条件
            TreeNode *right = trimBST(root->right, low, high);
            return right;
        }
        if (root->val > high)
        {
            TreeNode *left = trimBST(root->left, low, high);
            return left;
        }
        // root->val in [low,high]，继续递归直到不满足条件
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};