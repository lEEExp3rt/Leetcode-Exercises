/**
 * @brief 54 - Spiral Matrix
 * @link https://leetcode.cn/problems/spiral-matrix/
 * @author !EEExp3rt
 * @date 2025-03-09
 * @note 右下左上遍历，控制边界条件，不过代码写的有点史
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int row = matrix.size(), column = matrix[0].size(), size = row * column; // Size inforamtions.
        int up = 0, down = row - 1, left = 0, right = column - 1; // Boundaries.
        int cnt = 0, r = 0, c = 0; // Count and position.
        vector<int> ans(size); // Answer vector.
        while (cnt < size) {
            if (cnt == size - 1) {
                ans[cnt] = matrix[r][c];
                break;
            }
            // Move right.
            while (c < right && cnt < size) ans[cnt++] = matrix[r][c++];
            // Move down.
            while (r < down && cnt < size) ans[cnt++] = matrix[r++][c];
            // Move left.
            while (c > left && cnt < size) ans[cnt++] = matrix[r][c--];
            // Move up.
            while (r > up && cnt < size) ans[cnt++] = matrix[r--][c];
            // New start point.
            r++;
            c++;
            // Update boundaries.
            right--;
            down--;
            left++;
            up++;
        }
        return ans;
    }
};