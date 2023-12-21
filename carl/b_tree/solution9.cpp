#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/minimum-depth-of-binary-tree/
最小深度, 是从根节点到最近叶子节点的最短路径上的节点数量
*/
class Solution
{
public:
    /*
     递归三部曲：
     1. 确定入参和返回值
     2. 确定终止条件
     3. 确定单层逻辑
     */
    int minDepth(TreeNode *node)
    {
        // 终止条件
        if (node == NULL)
            return 0;
        // 单层逻辑
        int leftDeepth = minDepth(node->left);
        int rightDeepth = minDepth(node->right);
        if (node->left == NULL && node->right != NULL)
        {
            leftDeepth = 1 + rightDeepth;
        }
        if (node->left != NULL && node->right == NULL)
        {
            rightDeepth = 1 + leftDeepth;
        }

        return 1 + min(leftDeepth, rightDeepth);
    }
};