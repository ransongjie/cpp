#include <iostream>
#include "TreeNode.h"
using namespace std;
/**
 * https://leetcode.cn/problems/invert-binary-tree/
 * 翻转二叉树
 * 交换左右孩子的地址
 */
class Solution {
public:
    // 前序遍历
    /**
     * 递归三部曲：
     * 1. 确定入参和返回值
     * 2. 确定终止条件
     * 3. 确定单层逻辑
     */
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};