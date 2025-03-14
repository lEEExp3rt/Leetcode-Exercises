/**
 * @brief 94 - Binary Tree Inorder Traversal
 * @link https://leetcode.cn/problems/binary-tree-inorder-traversal/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 迭代法，用一个栈直接搞定，递归法更是无需多言
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<pair<TreeNode*, bool>> stack;
        vector<int> ans;
        stack.push({root, false});
        while (stack.size()) {
            auto [node, checked] = stack.top();
            stack.pop();
            if (checked) {
                ans.push_back(node->val);
            } else {
                TreeNode *l = node->left, *r = node->right;
                if (r) stack.push({r, false});
                stack.push({node, true});
                if (l) stack.push({l, false});
            }
        }
        return ans;
    }
};