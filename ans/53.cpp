/**
 * @brief 53 - Maximum Subarray
 * @link https://leetcode.cn/problems/maximum-subarray/
 * @author !EEExp3rt
 * @date 2025-03-07
 * @note 前缀和代入秒了，维护一个前缀和最小和最大的子数组的和，最大的减去最小的就是子数组和最大的子数组
 * @note 二编：官方题解提供了一个线段树的解法，非常牛逼，它可以得到任意区间 [l,r] 的子数组和，以树形方式存储后就可以在 O(log n) 时间内得到任意区间的子数组和，适用于大规模查询操作；但就本题而言，前缀和已经足够牛逼了，代码量少且性能优秀
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int presum = nums[0], max = nums[0], min = 0;
        for (int i = 1; i < nums.size(); ++i) {
            min = std::min(min, presum);
            presum += nums[i];
            max = std::max(max, presum - min);
            cout << presum << " " << min << " " << max << endl;
        }
        return max;
    }
};