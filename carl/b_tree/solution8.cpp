#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/maximum-depth-of-binary-tree/
二叉树的最大深度
*/
class solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return getdepth(root);
    }

    int getdepth(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int leftDeepth = getdepth(node->left);
        int rightDeepth = getdepth(node->right);
        return 1 + max(leftDeepth, rightDeepth);
    }
};