#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/delete-node-in-a-bst
删除二叉搜索树中的节点

第1种情况：没找到删除的节点，遍历到空节点直接返回了
第2种情况：左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
第3种情况：其左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
第4种情况：其右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
第5种情况：左右孩子节点都不为空，
则将删除节点的左子树放到删除节点的右子树的最左面节点的左孩子的位置，
并返回删除节点右孩子为新的根节点。
*/
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // 1
        if (root == nullptr)
            return nullptr;
        // 找到了要删除的结点
        if (root->val == key)
        {
            // 2
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            // 3
            if (root->left != nullptr && root->right == nullptr)
            {
                auto left = root->left;
                delete root;
                return left;
            }
            // 4
            if (root->left == nullptr && root->right != nullptr)
            {
                auto right = root->right; // auto
                delete root;
                return right;
            }
            // 5
            if (root->left != nullptr && root->right != nullptr)
            {
                TreeNode *rn = root->right;
                // 寻找右孩子的最左结点p
                TreeNode *p = rn;
                while (p->left != nullptr)
                {
                    p = p->left;
                }
                // 将左孩子作p的左孩子
                p->left = root->left;
                delete root;
                return rn;
            }
        }
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        return root;
    }
};