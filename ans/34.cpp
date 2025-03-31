/**
 * @brief 34 - Find First and Last Position of Element in Sorted Array
 * @link https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 * @author !EEExp3rt
 * @date 2025-03-31
 * @note 非常基本的题，但是好麻烦，直接看了评论区大神的答案，这样做更加清晰
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int m, left = -1, right = -1;
        while (l <= r) {
            m = (l + r) / 2;
            int n = nums.at(m);
            if (n == target) {
                r = m - 1;
                left = m;
            } else if (n < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            m = (l + r) / 2;
            int n = nums.at(m);
            if (n == target) {
                l = m + 1;
                right = m;
            } else if (n < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return {left, right};
    }
};