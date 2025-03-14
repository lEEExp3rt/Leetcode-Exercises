/**
 * @brief 104 - Maximum Depth of Binary Tree
 * @link https://leetcode.cn/problems/maximum-depth-of-binary-tree/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 递归直接秒
 * @note 二编：迭代法使用广度优先搜索，每一层的节点放在一个队列里
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};