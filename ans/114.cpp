/**
 * @brief 114 - Flatten Binary Tree to Linked List
 * @link https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
 * @author !EEExp3rt
 * @date 2025-03-15
 * @note 我勒个韶钢，直接拿下了；我的原地算法和题解想的一致，就是使用递归，找到当前节点的左子树的最右子节点，然后把右子树整个接到这个左子树的最右子节点的右子树上，相当于不断旋转，右接左，然后左移到右，但是我忘记了这个操作之后要把左子树设为nullptr，就加了这一步就直接拿下了
 * @note 二编：看了一下官方题解的做法，好像直接迭代也能做，所以我的代码可能不是最简的
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
    void flatten(TreeNode* root) {
        if (!root) return ; // Empty node, do nothing.
        TreeNode *left = root->left, *right = root->right; // Record left and right child.
        flatten(left); // Flatten left.
        flatten(right); // Flatten right.
        // Find the rightmost node of left child.
        TreeNode *node = left;
        if (!node) return ;
        while (node->right) node = node->right;
        root->right = left; // Connect left to right.
        node->right = right; // Connect right to the rightmost node of left.
        root->left = nullptr; // Set left to nullptr.
        return ;
    }
};