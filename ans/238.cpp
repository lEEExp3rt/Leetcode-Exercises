/**
 * @brief 238 - Product of Array Except Self
 * @link https://leetcode.cn/problems/product-of-array-except-self/
 * @author !EEExp3rt
 * @date 2025-03-07
 * @note 前缀积和后缀积，当前位置的结果等于前缀积乘以后缀积
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= prefix;
            prefix *= nums[i];
            ans[n - i - 1] *= suffix;
            suffix *= nums[n - i - 1];
        }
        return ans;
    }
};