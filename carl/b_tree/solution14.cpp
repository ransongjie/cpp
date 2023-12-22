#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/find-bottom-left-tree-value/
找树左下角的值
最底层最左结点

INT_MIN
*/
class Solution
{
public:
    // 记录最大深度和最左结点
    int max_depth = INT_MIN;
    int most_left;
    // 前序遍历，达到新深度记录结点的值，可以先得到最左结点
    void traversal(TreeNode *root, int depth)
    {
        // 叶子结点，并且到达新深度，记录结点值，结合前序遍历，得到最底层最左结点的值
        if (root->left == NULL && root->right == NULL)
        {
            if (depth > max_depth)
            {
                max_depth = depth;
                most_left = root->val;
            }
        }
        // 递归与回溯
        if (root->left != NULL)
        {
            depth++;
            traversal(root->left, depth);
            depth--;
        }
        if (root->right != NULL)
        {
            depth++;
            traversal(root->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        traversal(root, 0);
        return most_left;
    }
};