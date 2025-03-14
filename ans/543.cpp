/**
 * @brief 543 - Diameter of Binary Tree
 * @link https://leetcode.cn/problems/diameter-of-binary-tree/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 简单题，拼尽全力无法战胜...参考了官方题解，其实就是要求出每个树的左右子树高度然后得到这个树的最大树高，所以对于这个树来说的最大直径就是左子树高加上右子树高，然后再比较全局的每个子树的最大高度，取最大值
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
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 1;
        maxHeight(root);
        return maxDiameter - 1;
    }
private:
    int maxDiameter = 0;
    int maxHeight(TreeNode* root) {
        if (!root) return 0;
        int left = maxHeight(root->left);
        int right = maxHeight(root->right);
        maxDiameter = max(maxDiameter, left + right + 1);
        return max(left, right) + 1;
    }
};