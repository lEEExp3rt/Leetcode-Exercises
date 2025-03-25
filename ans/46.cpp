/**
 * @brief 46 - Permutations
 * @link https://leetcode.cn/problems/permutations/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 这题思路其实简单的，主要我和题解的区别是题解每次把当前元素和第一个元素交换，这样就可以直接使用后面的元素进行下一层递归了，这里会快很多
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 1) return {{nums[0]}};
        vector<vector<int>> ans;
        unordered_set<int> numbers(nums.begin(), nums.end());
        for (const int &num : nums) {
            numbers.erase(num);
            vector<int> subnums(numbers.begin(), numbers.end());
            vector<vector<int>> subs = permute(subnums);
            for (auto &sub : subs) {
                sub.push_back(num);
                ans.push_back(sub);
            }
            numbers.insert(num);
        }
        return ans;
    }
};