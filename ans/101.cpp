/**
 * @brief 101 - Symmetric Tree
 * @link https://leetcode.cn/problems/symmetric-tree/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note copilot写的递归判断函数 isMirror，判断左子树和右子树是否对称
 * @note 二编：迭代法用队列来判断，每次取两个节点，如果值不相等，返回false，如果值相等，则将左子树的左节点 & 右子树的右节点、左子树的右节点 & 右子树的左节点 两组分别入队，然后判断，直到队列为空
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
    bool isSymmetric(TreeNode* root) {
        return root ? isMirror(root->left, root->right) : true;
    }
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};