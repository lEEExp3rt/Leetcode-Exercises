/**
 * @brief 189 - Rotate Array
 * @link https://leetcode.cn/problems/rotate-array/
 * @author !EEExp3rt
 * @date 2025-03-07
 * @note 约瑟夫环直接爆杀
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size(); 
        vector<int> ans(nums.size());
        for (int i = 0; i < n; i++) ans[(i + k) % n] = nums[i];
        nums = ans;
    }
};