#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
二叉树的最近公共祖先

pq分别是某一结点的左右孩子
p是q的孩子，q是p的孩子
pq不存在，返回NULL
*/
class Solution
{
public:
    // 后续遍历，才能找到最近公共祖先
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 递归出口，找到结点
        if (root == NULL || root == p || root == q)
            return root;
        // 当前层逻辑，后续遍历
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL)
        { // pq分别是某一结点的左右孩子
            return root;
        }
        if (left != NULL && right == NULL)
        { // p是q的孩子，q是p的孩子
            return left;
        }
        if (left == NULL && right != NULL)
        { // p是q的孩子，q是p的孩子
            return right;
        }
        return NULL; // pq不存在，返回NULL
    }
};