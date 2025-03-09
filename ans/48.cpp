/**
 * @brief 48 - Rotate Image
 * @link https://leetcode.cn/problems/rotate-image/
 * @author !EEExp3rt
 * @date 2025-03-09
 * @note 整个方阵就像一个“回”字，从外层到内层逐层剥离，每层的上换到右，右换到下，下换到左，左换到上，写一个交换函数专门换四个元素，然后用二重循环，第一重循环层次，第二层循环每个元素
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        // Rotate layer by layer.
        for (int layer = 0; layer < n / 2; layer++) {
            // Index = 0, 1, ..., n - 1 - layer * 2 (skip the last one).
            for (int index = 0; index < n - 1 - layer * 2; index++) {
                swap4(matrix, layer, index);
            }
        }
    }
private:
    int n; // Array size.
    using point = pair<int, int>;
    inline void swap4(vector<vector<int>>& matrix, int layer, int index) {
        point p1 = {layer, index + layer}, // Up.
              p2 = {index + layer, n - 1 - layer}, // Right.
              p3 = {n - 1 - layer, n - 1 - layer - index}, // Down.
              p4 = {n - 1 - layer - index, layer}; // Left.
        int tmp1 = matrix[p1.first][p1.second],
            tmp2 = matrix[p2.first][p2.second],
            tmp3 = matrix[p3.first][p3.second],
            tmp4 = matrix[p4.first][p4.second];
        // Up -> Right.
        matrix[p2.first][p2.second] = tmp1;
        // Right -> Down.
        matrix[p3.first][p3.second] = tmp2;
        // Down -> Left.
        matrix[p4.first][p4.second] = tmp3;
        // Left -> Up.
        matrix[p1.first][p1.second] = tmp4;
    }
};