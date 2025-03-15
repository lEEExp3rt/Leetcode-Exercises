/**
 * @brief 98 - Validate Binary Search Tree
 * @link https://leetcode.cn/problems/validate-binary-search-tree/
 * @author !EEExp3rt
 * @date 2025-03-15
 * @note 呆那真服了，边界条件要判断，主要是刚好卡住了 int 的最值，所以边界需要专门判断；总体来说是判断一个树的树根值是否在左边界值和右边界值间，且左子树小于根小于右子树
 * @note 二编：看了官方题解，可以用树的中序遍历来判断是不是有序的序列，这个想法有点牛逼
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
    bool isValidBST(TreeNode* root) {
        return isValid(root, 0, 0, false, false);
    }
private:
    bool isValid(TreeNode* root, int left, int right, bool lb, bool rb) {
        if (!root) return true;
        bool l = lb ? root->val > left : true;
        bool r = rb ? root->val < right : true;
        return l && r &&
                isValid(root->left, left, root->val, lb, true) &&
                isValid(root->right, root->val, right, true, rb);
    }
};