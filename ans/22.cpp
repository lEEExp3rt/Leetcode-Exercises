/**
 * @brief 22 - Generate Parentheses
 * @link https://leetcode.cn/problems/generate-parentheses/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 最开始的做法是最笨的回溯，没有任何剪枝，通过了但是耗时非常高
 * @note 二编：添加了剪枝，判断任何一边的数量超过一半就剪枝
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<int> count = {1, 0};
        backtrace(n, "(", count);
        return ans;
    }
private:
    vector<string> ans;
    void backtrace(int n, string s, vector<int> &count) {
        if (count[0] > n || count [1] > n) return ;
        int len = n + n;
        if (s.size() == len) {
            int cnt = 0;
            for (int i = 0; i < len && cnt >= 0 && cnt <= len; i++) {
                if (s[i] == '(') cnt++;
                else cnt--;
            }
            if (cnt == 0) ans.push_back(s);
        } else {
            count[0]++;
            backtrace(n, s + "(", count);
            count[0]--;
            count[1]++;
            backtrace(n, s + ")", count);
            count[1]--;
        }
        return ;
    }
};