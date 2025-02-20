/**
 * @brief 1 - Two Sum
 * @link https://leetcode.cn/problems/two-sum
 * @author !EEExp3rt
 * @date 2025-02-19
 * @note 直接暴力求解
 */

#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};