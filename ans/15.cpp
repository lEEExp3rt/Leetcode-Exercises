/**
 * @brief 15 - 3Sum
 * @link https://leetcode.cn/problems/3sum/
 * @author !EEExp3rt
 * @date 2025-02-22
 * @note 一个比较麻烦的方法，基于双指针法，但是使用一个字典来统计每个元素出现的次数，然后用二重循环枚举两个元素，再基于字段判断第三个元素是否存在以及数量上是否满足条件，最后输出的时候加上一个去重的逻辑，不是最优但是能用
 */

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::unordered_map<int, int> cnts;
        for (const int& num: nums) cnts[num]++;
        for (const auto& pair1: cnts) {
            for (const auto& pair2: cnts) {
                if (pair1.first == pair2.first && pair1.second < 2) continue;
                int target = 0 - pair1.first - pair2.first;
                if (!(pair1.first <= pair2.first && pair2.first <= target)) continue;
                if (cnts.count(target) && check(cnts, pair1.first, pair2.first, target)) {
                    ans.push_back({pair1.first, pair2.first, target});
                }
            }
        }
        return ans;
    }
private:
    inline bool check(const std::unordered_map<int, int>& cnts, int a, int b, int c) {
        if (a != b && a != c && b != c) return true;
        if (a == b && a == c) return cnts.at(a) >= 3;
        return (a == b) ? (cnts.at(a) >= 2) : (cnts.at(b) >= 2);
    }
};