/**
 * @brief 128 - Longest Consecutive Sequence
 * @link https://leetcode.cn/problems/longest-consecutive-sequence/
 * @author !EEExp3rt
 * @date 2025-02-21
 * @note 首先使用一个哈希表对数组去重，然后遍历哈希表，如果这个元素不是连续序列的开头，那么就跳过，否则就向后遍历，直到找到连续序列的结尾，更新最长连续序列的长度
 */

#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (const int& num: nums) {
            set.insert(num);
        }
        int longest = 0;
        for (const int& num: set) {
            if (!set.count(num - 1)) {
                int cur = num;
                for (; set.count(cur); ++cur);
                longest = std::max(longest, cur - num);
            }
        }
        return longest;
    }
};