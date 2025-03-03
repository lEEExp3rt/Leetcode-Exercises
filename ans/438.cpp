/**
 * @brief 438 - Find All Anagrams in a String
 * @link https://leetcode.cn/problems/find-all-anagrams-in-a-string/
 * @author !EEExp3rt
 * @date 2025-03-03
 * @note 优化过的滑动窗口，时间开销主要体现在遍历两个字符串上，对于p字符串来说每次都是固定的，重复在每轮循环中遍历是额外不必要的开销，因此只做一次即可，存放内容到一个哈希表中，对于s字符串每轮循环移除最左侧的字符，同时加入最右侧的字符，避免整个字符串的迭代
 * @note 官方题解使用的是一个长度为 26 的 vector用于统计，和我的做法其实本质上一样，但是使用 vector 可以优化查找的时间，表现上更优
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = p.size(), left = 0, right = len - 1;
        vector<int> res;
        unordered_map<char, int> mps, mpp;
        for (int i = 0; i < len - 1; i++) mps[s[i]]++;
        for (int i = 0; i < len; i++) mpp[p[i]]++;
        while (right < s.size()) {
            mps[s[right]]++;
            if (mps == mpp) res.push_back(left);
            if (mps[s[left]] == 1) mps.erase(s[left]);
            else mps[s[left]]--;
            left++;
            right++;
        }
        return res;
    }
};