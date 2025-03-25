/**
 * @brief 35 - Search Insert Position
 * @link https://leetcode.cn/problems/search-insert-position/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 送分题
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m;
        while (i <= j) {
            m = (i + j) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) i = m + 1;
            else if (nums[m] > target) j = m - 1;
        }
        return i;
    }
};