/**
 * @brief 41 - First Missing Positive
 * @link https://leetcode.cn/problems/first-missing-positive/
 * @author !EEExp3rt
 * @date 2025-03-08
 * @note 我只想到了使用哈希表的空间复杂度为 O(n) 的解法，但是题目要求空间复杂度为 O(1)，参考了题解后知道原来有个原地哈希的牛逼算法，是真牛逼，就是原地调用这个原数组，数 i 应该在 i - 1 的位置
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        const int n = nums.size();
        for (const int& num: nums) s.insert(num);
        for (int i = 1; i <= n; i++)
            if (!s.count(i)) return i;
        return n;
    }
};