#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
从中序与后序遍历序列构造二叉树

根结点：以后续遍历数组最后1个元素，作为中序遍历数组的分割结点，得到左中序子数组和右中序子数组
已经使用后续遍历数组的最后1个元素，使用左中序子数组size分割后续遍历数组（因为左右中），得到左后序子数组和后中序子数组
左子树：递归左中序子数组和左后序子数组
右子树：递归右中序子数组和右后序子数组

统一区间划分规则，左闭右开
*/
class Solution
{
private:
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        // 分割结点
        int v = postorder[postorder.size() - 1];
        TreeNode *p = new TreeNode(v);

        // 叶子结点，postorder只有1个元素
        if (postorder.size() == 1)
            return p;

        // 左中序子数组和右中序子数组
        int idx;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (v == inorder[i])
            {
                idx = i;
                break;
            }
        }
        // 统一规则左闭右开
        vector<int> inLeft(inorder.begin(), inorder.begin() + idx);
        vector<int> inRight(inorder.begin() + idx + 1, inorder.end()); // +1跳过分割结点
        // 左后序子数组和后中序子数组
        // 丢弃后续遍历数组末尾结点
        postorder.resize(postorder.size() - 1);
        int leftSize = inLeft.size();
        vector<int> postLeft(postorder.begin(), postorder.begin() + leftSize);
        vector<int> postRight(postorder.begin() + leftSize, postorder.end());

        // 递归
        p->left = traversal(inLeft, postLeft);
        p->right = traversal(inRight, postRight);
        return p;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }
};