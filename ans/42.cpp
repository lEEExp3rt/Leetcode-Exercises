/**
 * @brief 42 - Trapping Rain Water
 * @link https://leetcode.cn/problems/trapping-rain-water/
 * @author !EEExp3rt
 * @date 2025-02-26
 * @note 参考题解评论区的思路，先找到最高的柱子，然后左侧水量一定的递增的，从左往右遍历；右侧水量一定是递减的，从右往左遍历
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int maxPos = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > height[maxPos]) {
                maxPos = i;
            }
        }
        int cnt = 0, tmp = 0;
        for (int i = 0; i < maxPos; i++) {
            tmp = std::max(height[i], tmp);
            cnt += tmp - height[i];
        }
        tmp = 0;
        for (int i = height.size() - 1; i > maxPos; i--) {
            tmp = std::max(height[i], tmp);
            cnt += tmp - height[i];
        }
        return cnt;
    }
};

int main() {
    //std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    Solution sol;
    std::cout << sol.trap(height) << std::endl;
    return 0;
}