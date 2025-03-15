/**
 * @brief 199 - Binary Tree Right Side View
 * @link https://leetcode.cn/problems/binary-tree-right-side-view/
 * @author !EEExp3rt
 * @date 2025-03-15
 * @note 直接层序遍历，每层的最后一个节点加入列表即可，轻松拿下
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size - 1; i++) {
                TreeNode *node = q.front();
                q.pop();
                TreeNode *left = node->left, *right = node->right;
                if (left) q.push(left);
                if (right) q.push(right);
            }
            TreeNode *node = q.front();
            q.pop();
            TreeNode *left = node->left, *right = node->right;
            if (left) q.push(left);
            if (right) q.push(right);
            ans.push_back(node->val);
        }
        return ans;
    }
};