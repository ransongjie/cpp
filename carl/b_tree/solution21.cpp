#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/validate-binary-search-tree/
验证二叉搜索树
是否二叉搜索树
*/
class Solution
{
public:
    long long pre = LONG_MIN;

    // 递归除了判断值大小，还要求左右子树也是二叉搜索树
    bool isValidBST(TreeNode *root)
    {
        // 递归出口，空树也是二叉搜索树
        if (root == NULL)
            return true;
        // 当前层逻辑
        bool left = isValidBST(root->left);
        // 中序遍历有序
        if (pre < root->val)
            pre = root->val;
        else
            return false; // 不满足条件直接返回
        bool right = isValidBST(root->right);
        return left && right;
    }
};
