#include <iostream>
#include <vector>
#include <string>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/binary-tree-paths/
二叉树的所有路径
回溯和递归是一一对应的，有一个递归，就要有一个回溯, 回溯要和递归永远在一起
int》
*/
class Solution
{
private:
    // 递归入参和出参
    // 回溯，前序遍历, a->b->c
    void traversal(TreeNode *cur, vector<int> &path, vector<string> &ans)
    { // 引用拷贝
        path.push_back(cur->val);
        // 递归出口
        // 到达叶子结点，构建路径
        if (cur->left == NULL && cur->right == NULL)
        {
            // 前size-1个结点需要->
            int size = path.size();
            string a = "";
            for (int i = 0; i < size - 1; i++)
            {
                a += to_string(path[i]);
                a += "->";
            }
            // 最后1个结点无需->
            a += to_string(path[size - 1]);
            ans.push_back(a);
            return;
        }
        // 递归与回溯
        if (cur->left != NULL)
        {
            traversal(cur->left, path, ans);
            path.pop_back();
        }
        if (cur->right != NULL)
        {
            traversal(cur->right, path, ans);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        vector<int> path;
        if (root == NULL)
            return ans;
        traversal(root, path, ans);
        return ans;
    }
};