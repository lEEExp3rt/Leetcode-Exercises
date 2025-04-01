/**
 * @brief 215 - Kth Largest Element in an Array
 * @link https://leetcode.cn/problems/kth-largest-element-in-an-array/
 * @author !EEExp3rt
 * @date 2025-04-01
 * @note 最笨的方法，直接调用一个最大堆，把所有元素插进去，然后 pop k次
 * @note 二编：官方题解的做法是快速排序的变种，因为快速排序是找一个中间值，然后左侧子数组全部比它小，右侧全部比它大，所以只要找到第 k 个元素作为中间值就可以了
 * @note 三编：参考了评论区大神的，可以使用桶排序，因为题目描述给了每个元素的范围，直接建立桶，然后从最大开始逐个减去即可，这个仅限特定题目条件下使用
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap;
        for (int i = 0; i < nums.size(); i++) heap.push(nums[i]);
        for (int i = 0; i < k - 1; i++) heap.pop();
        return heap.top();
    }
};