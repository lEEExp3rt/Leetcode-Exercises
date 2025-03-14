/**
 * @brief 108 - Convert Sorted Array to Binary Search Tree
 * @link https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 参考评论区，原来直接递归构造就好了
 * @note 二编：参考了官方题解，这样基于有序的数组的中序遍历直接构造二叉树是必然平衡的，至于证明过程，我也不会
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return buildTree(0, nums.size() - 1);
    }
private:
    vector<int> nums;
    TreeNode* buildTree(int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(left, mid - 1);
        root->right = buildTree(mid + 1, right);
        return root;
    }
};