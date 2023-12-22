#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/path-sum-ii/description/
路径总和 II，所有从根到叶子等于sum的路径

路径总和ii要遍历整个树，找到所有路径，所以递归函数不要返回值！
*/
class solution
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void traversal(TreeNode *cur, int count)
    {
        // 到达叶子结点判断count是否为0，则存在一条从根到叶子等于sum的路径
        if (cur->left == NULL && cur->right == NULL && count == 0)
        {
            ans.push_back(path);
            return;
        }
        if (cur->left == NULL && cur->right == NULL && count != 0)
        {
            return;
        }
        // 递归回溯
        if (cur->left != NULL)
        {
            path.push_back(cur->left->val); // ->left
            count -= cur->left->val;
            traversal(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }
        if (cur->right != NULL)
        {
            path.push_back(cur->right->val);
            count -= cur->right->val;
            traversal(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        ans.clear();
        path.clear();
        if (root == NULL)
            return ans;
        path.push_back(root->val);
        traversal(root, sum - (root->val));
        return ans;
    }
};