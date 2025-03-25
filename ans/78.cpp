/**
 * @brief 78 - Subsets
 * @link https://leetcode.cn/problems/subsets/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 参考了官方题解，说实话本来想到了可以用二进制串来枚举所有的可能，但是没有继续实现这个方法，比较悲哀
 * @note 二编：使用回溯法实际上是这样：从左往右扫描每一个元素，然后对于每个元素，他都有选入下一个集合和不选入下一个集合两种状态，相当于二进制串
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;
    }
};