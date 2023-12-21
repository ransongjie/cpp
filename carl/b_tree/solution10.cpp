#include <iostream>
#include "TreeNode.h"
using namespace std;
/*
https://leetcode.cn/problems/count-complete-tree-nodes/
完全二叉树的节点个数
就是求结点个数
*/
class Solution {
public:
    int countNodes(TreeNode* node) {
        if (node == NULL) return 0;
        int leftDeepth = countNodes(node->left);
        int rightDeepth = countNodes(node->right);
        return 1+leftDeepth+rightDeepth;
    }
};