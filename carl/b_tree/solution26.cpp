#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/insert-into-a-binary-search-tree/
二叉搜索树中的插入操作

只要按照二叉搜索树的规则去遍历，遇到空节点就插入节点就可以了。
*/
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};