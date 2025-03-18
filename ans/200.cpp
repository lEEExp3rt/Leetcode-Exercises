/**
 * @brief 200 - Number of Islands
 * @link https://leetcode.cn/problems/number-of-islands/
 * @author !EEExp3rt
 * @date 2025-03-18
 * @note 刚开始做图论，上来有点没思路，参考了题解的深度优先做法，思路重新打开，但这题非常骚，传入的二维数组是 char 类型而不是数字，所以判断是否是岛屿还要判断是否等于 '1'
 * @note 二编：广度优先搜索好像效果会更好，但我觉得其实和 DFS 没有差特别多
 * @note 三编：并查集这东西也可以，但是学的有点久了忘记怎么做了
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
private:
    int cnt = 0;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return ;
        if (grid[i][j] == '0') return ;
        grid[i][j] = '0';
        dfs(grid, i - 1, j); // Left.
        dfs(grid, i + 1, j); // Right.
        dfs(grid, i, j - 1); // Up.
        dfs(grid, i, j + 1); // Down.
        return ;
    }
};