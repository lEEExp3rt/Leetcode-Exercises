/**
 * @brief 17 - Letter Combinations of a Phone Number
 * @link https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 轻松拿下，先创建每个数字到对应字母的映射，然后递归读取，把每个数字中的字符和下一个拼接起来
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        for (const char &digit : digits) {
            maps.push_back(mapping(digit));
        }
        combination("", 0);
        return ans;
    }
private:
    vector<vector<string>> maps;
    vector<string> ans;
    vector<string> mapping(char digit) {
        switch (digit) {
            case '2': return {"a", "b", "c"};
            case '3': return {"d", "e", "f"};
            case '4': return {"g", "h", "i"};
            case '5': return {"j", "k", "l"};
            case '6': return {"m", "n", "o"};
            case '7': return {"p", "q", "r", "s"};
            case '8': return {"t", "u", "v"};
            case '9': return {"w", "x", "y", "z"};
        }
        return {};
    }
    void combination(string cur, int index) {
        vector<string> &map = maps.at(index);
        if (index == maps.size() - 1) {
            for (auto c : map) ans.push_back(cur + c);
        } else {
            for (auto c : map) combination(cur + c, index + 1);
        }
    }
};