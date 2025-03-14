/**
 * @brief 3340 - Balanced Numbers
 * @link https://leetcode.cn/problems/check-balanced-string/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 无需多言
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        if (n % 2) num += '0';
        int odd = 0, even = 0;
        for (int i = 0; i < n; i += 2) {
            even += num[i] - '0';
            odd += num[i + 1] - '0';
        }
        return odd == even;
    }
};