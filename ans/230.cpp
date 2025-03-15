/**
 * @brief 230 - Kth Smallest Element in a BST
 * @link https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
 * @author !EEExp3rt
 * @date 2025-03-15
 * @note 直接中序遍历得到 BST 的序列，然后直接返回第 K 个值就完事，没想到居然击败 100%
 * @note 二编：官方题解的中序遍历，无需使用 vector，直接在遍历过程中判断是否到达第 K 个值即可
 * @note 三编：题目进阶要求，如果树经常变动且需频繁查找第 K 个值，那么可以记录每个子树的根节点的子节点数，这样如果左子树的节点数大于等于 K，那么就在左子树中查找第 K 个值，否则在右子树中查找第 K - 左子树节点数 - 1 个值，有点牛逼
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        stack<pair<TreeNode*, bool>> s;
        s.push({root, false});
        while (!s.empty()) {
            auto [node, checked] = s.top();
            s.pop();
            if (checked) values.push_back(node->val);
            else {
                TreeNode *left = node->left, *right = node->right;
                if (right) s.push({right, false});
                s.push({node, true});
                if (left) s.push({left, false});
            }
        }
        return values[k - 1];
    }
};