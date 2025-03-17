/**
 * @brief 124 - Binary Tree Maximum Path Sum
 * @link https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 * @author !EEExp3rt
 * @date 2025-03-18
 * @note 轻松拿下，直接超级大递归，递归每次返回左路、右路、自己节点值三者的最大值给上一级，同时记录总的最大值，然后就可以轻松拿下了，但是这题要考虑的边界条件很多，非常傻逼，导致主播提交了很多次才最终拿下，不过困难提也就这样嘛，区区15分钟就写完了，其中debug花了10分钟
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
    int maxPathSum(TreeNode* root) {
        if (!root->left && !root->right) return root->val;
        maxSum = -1001;
        maxSubpathSum(root);
        return maxSum;
    }
private:
    int maxSum;
    int maxSubpathSum(TreeNode* root) {
        if (!root) return 0;
        int left = maxSubpathSum(root->left);
        int right = maxSubpathSum(root->right);
        int m = max(root->val, max(left + root->val, right + root->val));
        maxSum = max(maxSum, max(m, left + right + root->val));
        return m;
    }
};