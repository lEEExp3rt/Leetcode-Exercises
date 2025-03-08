/**
 * @brief 73 - Set Matrix Zeroes
 * @link https://leetcode.cn/problems/set-matrix-zeroes/
 * @author !EEExp3rt
 * @date 2025-03-08
 * @note 原地算法，其实就是把二维矩阵的标题行和标题列用来记录这一行或列是否需要全部置零，但是标题行和标题列需要特殊考虑，防止特殊情况没有考虑到，谁写谁知道坑在哪
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i, j;

        // 单独检查第一行和第一列
        bool row = matrix[0][0] == 0, col = matrix[0][0] == 0;
        for (i = 1; i < m && !col; i++) {
            if (matrix[i][0] == 0) col = true;
        }
        for (j = 0; j < n && !row; j++) {
            if (matrix[0][j] == 0) row = true;
        }
        // 检查第二行第二列开始的位置
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }

        // 从第二行第二列开始替换
        for (i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < n; j++) matrix[i][j] = 0;
            }
        }
        for (j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < m; i++) matrix[i][j] = 0;
            }
        }
        // 替换第一行和第一列
        if (row) {
            for (j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if (col) {
            for (i = 0; i < m; i++) matrix[i][0] = 0;
        }

        return ;
    }
};