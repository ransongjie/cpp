#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
将有序数组转换为二叉搜索树

二分构造平衡二叉BST
int mid = left + ((right - left) / 2); 先减后加防止越界
[left,right]闭区间，统一循环不变量
*/
class Solution
{
private:
    TreeNode *traversal(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size() - 1);
    }
};
