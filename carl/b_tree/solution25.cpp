#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
二叉搜索树的最近公共祖先

当我们从上向下去递归遍历，第一次遇到 cur节点是数值在[q, p]区间中，那么cur就是 q和p的最近公共祖先。
如何利用二叉搜索树的有序性，寻找[pV,curV,qV]区间
在遍历二叉搜索树的时候就是寻找区间cur在[p->val, q->val]或[q->val, p->val]之间
*/
class Solution
{
private:
    TreeNode *traversal(TreeNode *cur, TreeNode *p, TreeNode *q)
    {
        if (cur == NULL)
            return cur;
        // 利用二叉搜索树有序性，都大走左子树
        if (cur->val > p->val && cur->val > q->val)
        {
            TreeNode *left = traversal(cur->left, p, q);
            if (left != NULL)
                return left;
        }
        // 都小走右子树
        if (cur->val < p->val && cur->val < q->val)
        {
            TreeNode *right = traversal(cur->right, p, q);
            if (right != NULL)
                return right;
        }
        // cur在p和q构成的区间中间
        return cur;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return traversal(root, p, q);
    }
};