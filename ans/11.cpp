/**
 * @brief 11 - Container With Most Water
 * @link https://leetcode.cn/problems/container-with-most-water/
 * @author !EEExp3rt
 * @date 2025-02-22
 * @note 双指针法，注意到面积是由短板决定的，首先从两边包夹，如果移动长板那么面积必然变小，所以需要移动短板往中间走，然后每次比较当前位置的面积与记录的最大面积，最后返回即可
 */

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            max = std::max(max, area(left, height[left], right, height[right]));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return max;
    }
private:
    inline int area(int x1, int y1, int x2, int y2) {
        return std::min(y1, y2) * (x2 - x1);
    }
};