/**
 * @brief 136 - Single Number
 * @link https://leetcode.cn/problems/single-number/
 * @author !EEExp3rt
 * @date 2025-04-02
 * @note 这谁想得到？用异或运算直接秒杀了，一个数和自身异或结果为0，和0异或为自身，所以遍历的时候直接异或，最后结果就是那个只有一次的数字了，无敌了
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (const int &num : nums) ret ^= num;
        return ret;
    }
};