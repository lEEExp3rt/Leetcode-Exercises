/**
 * @brief 236 - Lowest Common Ancestor of a Binary Tree
 * @link https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 * @author !EEExp3rt
 * @date 2025-03-18
 * @note 简单的思考，极致的效率，超凡的享受，首先先深度优先找到这两个节点，同时用一个双端队列记录找到目标节点时的路径，然后比较两个目标节点的队列，找到深度最大的公共节点就是所求节点
 * @note 二编：官方题解的方法一，如果在一个节点的其中一个子树找到了其中一个目标节点，在另一个子树找到了另一个目标节点，那么这个节点就是所求节点，同样是递归的自底向上的寻找，更简洁
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        que = deque<TreeNode*>();
        find(root, p);
        deque<TreeNode*> que1 = que;
        que.clear();
        find(root, q);
        deque<TreeNode*> que2 = que;
        TreeNode *node;
        while (que1.front() == que2.front()) {
            node = que1.front();
            que1.pop_front();
            que2.pop_front();
        }
        return node;
    }
private:
    deque<TreeNode*> que;
    bool find(TreeNode* root, TreeNode* target) {
        if (!root) return false;
        que.push_back(root);
        if (root == target) return true;
        bool flag = find(root->left, target) || find(root->right, target);
        if (!flag) que.pop_back();
        return flag;
    }
};