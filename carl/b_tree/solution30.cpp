#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/convert-bst-to-greater-tree/
把二叉搜索树转换为累加树

[2,3,5]累加为[10,8,5]就是逆中序遍历
*/
class Solution
{
private:
    int pre = 0;
    void traversal(TreeNode *cur)
    {
        if (cur == nullptr)
            return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        pre = 0;
        traversal(root);
        return root;
    }
};