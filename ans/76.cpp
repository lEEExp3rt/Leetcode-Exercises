/**
 * @brief 76 - Minimum Window Substring
 * @link https://leetcode.cn/problems/minimum-window-substring/
 * @author !EEExp3rt
 * @date 2025-03-06
 * @note 和官方题解完全一致，滑动窗口，先使用一个哈希表记录 t 中所有字符出现次数，然后右指针从左往右遍历 s，如果当前子串满足了 t 的字符数要求，就固定右指针，左移左指针，直到子串不满足，然后比较是否是最短的子串，如果是就更新，直到整个 s 遍历完成
 * @note 二编：对于字符串统计字符次数的，可以用数组代替哈希表
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, current;
        for (const char& c : t) need[c]++;

        string ans;
        int left = 0, right = 0, min = s.size() + 1;
        for (; right < s.size(); right++) {
            current[s[right]]++;
            if (check(need, current)) {
                while (check(need, current)) current[s[left++]]--;
                if (right - left + 2 < min) {
                    min = right - left + 2;
                    ans = s.substr(left - 1, min);
                }
            }
        }
        return ans;
    }
private:
    inline bool check(unordered_map<char, int>& need, unordered_map<char, int>& current) {
        for (auto& [c, cnt] : need) {
            if (!current.count(c) || current[c] < cnt) return false;
        }
        return true;
    }
};