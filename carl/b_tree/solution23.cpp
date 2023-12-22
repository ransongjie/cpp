#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/find-mode-in-binary-search-tree/
二叉搜索树中的众数
是二叉搜索树，相等元素相邻
非二叉搜索树，利用map<val,cnt>，根据cnt排序
*/
class Solution
{
private:
    // 相同元素出现次数，最大次数
    int count = 0;
    int max_count = 0;
    TreeNode *pre = NULL;
    vector<int> ans;
    // 中序遍历
    void searchBST(TreeNode *cur)
    {
        if (cur == NULL)
            return;
        searchBST(cur->left);
        // 统计当前元素出现次数
        if (pre == NULL)
        {
            count = 1;
        }
        else if (cur->val == pre->val)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        pre = cur;

        // 假设当前元素是众数
        if (count == max_count)
        {
            ans.push_back(cur->val);
        }

        // 当前元素不是众数
        if (count > max_count)
        {
            max_count = count;
            ans.clear();
            ans.push_back(cur->val);
        }

        searchBST(cur->right);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        count = 0;
        max_count = 0;
        pre = NULL;
        ans.clear();
        searchBST(root);
        return ans;
    }
};