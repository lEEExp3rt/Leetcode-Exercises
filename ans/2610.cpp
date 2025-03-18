/**
 * @brief 2610 - Convert An Array Into A 2D Array With Conditions
 * @link https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/
 * @author !EEExp3rt
 * @date 2025-03-18
 * @note 直接构造一个集合就完事
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        data = vector<unordered_set<int>>();
        vector<vector<int>> ans;
        // Scan all elements.
        for (const int& num: nums) {
            int index = 0;
            // Find the set to insert the element.
            for (; index < data.size(); index++) {
                unordered_set<int>& s = data.at(index);
                if (!s.count(num)) break;
            }
            if (index == data.size()) {
                data.push_back({num});
                ans.push_back({num});
            } else {
                data.at(index).insert(num);
                ans.at(index).push_back(num);
            }
        }
        return ans;
    }
private:
    vector<unordered_set<int>> data;
};