/**
 * @brief 3 - Longest Substring Without Repeating Characters
 * @link https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * @author !EEExp3rt
 * @date 2025-03-03
 * @note 使用一个哈希表记录每个子串的每个字符及其出现的位置索引，然后使用滑动窗口，如果右侧出现一个前面子串中已经出现的字符那么把从滑动窗口左侧开始直到出现重复的这个字符之间的字符串都删了，从新的位置开始算，直到末尾
 */

#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int left = 0, right = 0, max = 0;
        std::unordered_map<char, int> map;
        while (right < s.size()) {
            if (map.count(s[right])) {
                max = std::max(max, right - left);
                int tmp = map[s[right]];
                for (int i = left; i <= tmp; i++) map.erase(s[i]);
                left = tmp + 1;
            } 
            map[s[right]] = right;
            right++;
        }
        return std::max(max, right - left);
    }
};