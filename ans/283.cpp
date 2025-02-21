/**
 * @brief 283 - Move Zeroes
 * @link https://leetcode.cn/problems/move-zeroes/
 * @author !EEExp3rt
 * @date 2025-02-21
 * @note 首先将所有非零元素复制到一个新的数组中，然后将剩余的位置填充为零
 */

#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::vector<int> nonzeros;
        for (const int& num: nums) {
            if (num != 0) nonzeros.push_back(num);
        }
        int i = 0;
        for (; i < nonzeros.size(); i++) nums[i] = nonzeros[i];
        for (; i < nums.size(); i++) nums[i] = 0;
    }
};