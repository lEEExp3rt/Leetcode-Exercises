/**
 * @brief 560 - Subarray Sum Equals K
 * @link https://leetcode.cn/problems/subarray-sum-equals-k/
 * @author !EEExp3rt
 * @date 2025-03-04
 * @note 最初使用动态规划做，内存超限，后改用前缀和+哈希表，官方题解
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, presum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (const int& num : nums) {
            presum += num;
            if (mp.count(presum - k)) cnt += mp[presum - k];
            mp[presum]++;
        }
        return cnt;
    }
};