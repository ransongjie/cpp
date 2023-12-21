#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/sum-of-left-leaves/
左叶子之和
*/
class Solution
{
public:
    // 中序遍历，左根右更可能出现左叶子结点
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL) // 没有左孩子，没有左叶子结点
            return 0;
        int leftSum = sumOfLeftLeaves(root->left);
        // 判断左叶子结点
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            leftSum += root->left->val; //
        }
        int rightSum = sumOfLeftLeaves(root->right);
        leftSum += rightSum;
        return leftSum;
    }
};