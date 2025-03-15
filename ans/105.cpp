/**
 * @brief 105 - Construct Tree from Preorder and Inorder Traversal
 * @link https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * @author !EEExp3rt
 * @date 2025-03-16
 * @note 基本操作，pre的第一个元素是当前的根节点，然后在 in 中找到根节点对应的位置，in左侧都是左子节点，右侧都是右子节点，得到列表后代入递归，虽然笨但简单好想
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if (!len) return nullptr;
        int value = preorder[0]; // Root value.
        TreeNode *root = new TreeNode(value); // Build root node.
        // Handle subtrees.
        vector<int> pre, in;
        int index = 0;
        // Left subtree.
        for (; inorder[index] != value; index++) {
            in.push_back(inorder[index]);
            pre.push_back(preorder[index + 1]);
        }
        root->left = buildTree(pre, in);
        pre.clear();
        in.clear();
        // Right subtree.
        for (index++; index < len; index++) {
            in.push_back(inorder[index]);
            pre.push_back(preorder[index]);
        }
        root->right = buildTree(pre, in);
        return root;
    }
};