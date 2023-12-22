#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/search-in-a-binary-search-tree/
二叉搜索树中的搜索
根据BST左子树<根，右子树>根，选择遍历方向
*/
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // 递归出口
        if (root == NULL || root->val == val)
            return root;
        // 根据BST左子树<根，右子树>根，选择遍历方向
        TreeNode *ans = NULL;
        if (val > root->val)
            ans = searchBST(root->right, val);
        else
            ans = searchBST(root->left, val);
        return ans;
    }
};