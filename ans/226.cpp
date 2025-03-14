/**
 * @brief 226 - Invert Binary Tree
 * @link https://leetcode.cn/problems/invert-binary-tree/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 递归直接秒
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode *l = invertTree(root->left), *r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};