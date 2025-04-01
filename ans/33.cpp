/**
 * @brief 33 - Search in Rotated Sorted Array
 * @link https://leetcode.cn/problems/search-in-rotated-sorted-array/
 * @author !EEExp3rt
 * @date 2025-04-01
 * @note 直接用递归做二分查找，因为递归可以回溯，如果左半边找不到就去右半边找，右半边也找不到就说明没有，不存在，没想到击败100%了
 * @note 二编：官方题解的做法，每次先取中点，此时左子区间和右子区间肯定有一个是有序的，然后判断目标值是否在有序区间内，如果在就去有序区间内二分查找，如果在乱序区间内就重复这个过程
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
private:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (left >= right) return -1;

        int index = binarySearch(nums, left, mid - 1, target);
        if (index != -1) return index;
        index = binarySearch(nums, mid + 1, right, target);
        if (index != -1) return index;
        return -1;
    }
};