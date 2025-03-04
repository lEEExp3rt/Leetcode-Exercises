/**
 * @brief 239 - Sliding Window Maximum
 * @link https://leetcode.cn/problems/sliding-window-maximum/
 * @author !EEExp3rt
 * @date 2025-03-04
 * @note 参考了官方题解，注意到要求的是最大值，很容易想到可以使用优先队列，但是优先队列的删除左侧已经移除的元素比较麻烦，所以我们可以转化思路，每次滑动窗口时看堆顶元素是否在窗口内，如果不在就弹出，直到堆顶元素在窗口内即可，同时注意每次窗口滑动只会删除左侧一个元素和加入右侧一个元素
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), i = 0;
        vector<int> ans(n - k + 1);
        priority_queue<int> heap;
        unordered_map<int, int> cnt;
        for (; i < k; i++) {
            heap.push(nums[i]);
            cnt[nums[i]]++;
        }
        ans[0] = heap.top();
        for (; i < n; i++) {
            heap.push(nums[i]);
            if (cnt[nums[i - k]] == 1) cnt.erase(nums[i - k]);
            else cnt[nums[i - k]]--;
            cnt[nums[i]]++;
            while (!cnt.count(heap.top())) heap.pop();
            ans[i - k + 1] = heap.top();
        }
        return ans;
    }
};