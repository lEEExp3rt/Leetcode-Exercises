/**
 * @brief 74 - Search a 2D Matrix
 * @link https://leetcode.cn/problems/search-a-2d-matrix/
 * @author !EEExp3rt
 * @date 2025-03-26
 * @note 送分题
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = n - 1, mid;
        while (i <= j) {
            mid = (i + j) / 2;
            vector<int> &row = matrix.at(mid);
            if (row[0] <= target && target <= row[m - 1]) break;
            else if (row[0] > target) j = mid - 1;
            else if (row[m - 1] < target) i = mid + 1;
        }
        vector<int> &row = matrix.at(mid);
        return find(row.begin(), row.end(), target) != row.end();
    }
};