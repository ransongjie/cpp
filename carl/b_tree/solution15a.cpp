#include <iostream>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/path-sum/
路径总和，是否存在一条从根到叶子等于sum的路径

递归需要返回值
如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（这种情况就是本文下半部分介绍的113.路径总和ii）
如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。 （这种情况我们在236. 二叉树的最近公共祖先 (opens new window)中介绍）
如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（本题的情况）
*/
class Solution
{
private:
    // count累计到sum，改为累减到0
    bool traversal(TreeNode *cur, int count)
    {
        count -= cur->val;
        // 到达叶子结点判断count是否为0，则存在一条从根到叶子等于sum的路径
        if (cur->left == NULL && cur->right == NULL && count == 0)
        {
            return true;
        }
        if (cur->left == NULL && cur->right == NULL && count != 0)
        {
            return false;
        }
        // 递归回溯
        if (cur->left != NULL)
        {
            if (traversal(cur->left, count))
                return true; // 存在即可
        }
        if (cur->right != NULL)
        {
            if (traversal(cur->right, count))
                return true;
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        return traversal(root, sum);
    }
};