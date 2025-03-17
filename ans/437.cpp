/**
 * @brief 437 - Path Sum III
 * @link https://leetcode.cn/problems/path-sum-iii/
 * @author !EEExp3rt
 * @date 2025-03-17
 * @note 原来的想法是直接暴力干就完了，但是暴力做一个是效率比较低还有一个就是实现有些问题，参考了官方题解的前缀和解法，只能说这方法确实牛逼，深度优先递归遍历每条路径，并得到这条路径上的前缀和，然后基于前缀和操作，效率更高，注意到这条路径上的前缀和只对这条路径有效，因此这波递归完左右子树后记得把当前节点的前缀和从哈希表中删掉，不对其它路径造成影响；最骚的是前缀和可能会超过int类型，所以还要用长整数来表示前缀和，综上这题有点吊且鸡贼
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
    int pathSum(TreeNode* root, int targetSum) {
        prefixes[0] = 1;
        cnt = 0;
        prefix(root, 0, targetSum);
        return cnt;
    }
private:
    unordered_map<long long, int> prefixes;
    int cnt;
    void prefix(TreeNode* root, long long sums, int targetSum) {
        if (!root) return ;
        sums += root->val;
        if (prefixes.count(sums - targetSum)) cnt += prefixes.at(sums - targetSum);
        prefixes[sums]++;
        prefix(root->left, sums, targetSum);
        prefix(root->right, sums, targetSum);
        prefixes[sums]--;
    }
};