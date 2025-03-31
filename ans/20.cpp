/**
 * @brief 20 - Valid Parentheses
 * @link https://leetcode.cn/problems/valid-parentheses/
 * @author !EEExp3rt
 * @date 2025-03-31
 * @note 无需多言
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for (const char &ch : s) {
            int value = getType(ch);
            if (value <= 2) stk.push(value);
            else {
                int t = stk.top();
                if (value + t == 5) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
private:
    int getType(char ch) {
        switch (ch) {
            case '(': return 0;
            case '[': return 1;
            case '{': return 2;
            case '}': return 3;
            case ']': return 4;
            case ')': return 5;
        }
        return -1;
    }
};