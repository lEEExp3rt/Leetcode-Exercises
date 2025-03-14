/**
 * @brief 102 - Binary Tree Level Order Traversal
 * @link https://leetcode.cn/problems/binary-tree-level-order-traversal/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 使用一个队列就可以轻松拿下
 * @note 二编：使用队列进行迭代的做法属于 BFS，而递归的做法是 DFS，直接先创建一个用于返回的二维数组，然后根据每个节点的深度将其加入对应下标的数组中
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if (!level.empty()) ans.push_back(level);
        }
        return ans;
    }
};