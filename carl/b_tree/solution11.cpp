#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/balanced-binary-tree/
平衡二叉树
*/
class Solution
{
private:
    int getHeight(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftHeight = getHeight(node->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(node->right);
        if (rightHeight == -1)
            return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL) return true;
        return getHeight(root) == -1 ? false : true;
    }
};