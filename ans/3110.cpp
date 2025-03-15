/**
 * @brief 3110 - Score of A String
 * @link https://leetcode.cn/problems/score-of-a-string/
 * @author !EEExp3rt
 * @date 2025-03-15
 * @note 美好的周末从简单题开始
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int len = s.size(), score = 0;
        for (int i = 0; i < len - 1; i++) score += abs(s[i] - s[i + 1]);
        return score;
    }
};