#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/merge-two-binary-trees/
合并二叉树
将两棵二叉树合并，都有的结点相加，差异结点保留
将t1和t2统一合并到t1
*/
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
    {
        // 递归出口，相异结点，返回另一个结点
        if (t1 == NULL)
            return t2;
        if (t2 == NULL)
            return t1;
        // 当前操作
        t1->val += t2->val;
        // 继续递归
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};