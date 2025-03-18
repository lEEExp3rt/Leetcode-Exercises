/**
 * @brief 994 - Rotting Oranges
 * @link https://leetcode.cn/problems/rotting-oranges/
 * @author !EEExp3rt
 * @date 2025-03-18
 * @note DFS 直接拿下，配合一个队列使用，就是考虑一些细节处理
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // Get all rotten oranges.
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                switch (grid[i][j]) {
                    case 0: break;
                    case 1: fresh++; break;
                    case 2: q.push({i, j}); break;
                }
            }
        }
        if (q.empty()) return fresh ? -1 : 0;
        // Start rotting process.
        int cnt = -1;
        fresh += q.size();
        while (!q.empty()) {
            int sz = q.size();
            cnt++;
            for (int k = 0; k < sz; k++) {
                point p = q.front();
                q.pop();
                fresh--;
                point p1 = {p.first - 1, p.second};
                point p2 = {p.first + 1, p.second};
                point p3 = {p.first, p.second - 1};
                point p4 = {p.first, p.second + 1};
                if (p1.first >= 0 && p1.first < m && p1.second >= 0 && p1.second < n && grid[p1.first][p1.second] == 1) {
                    q.push(p1);
                    grid[p1.first][p1.second] = 2;
                }
                if (p2.first >= 0 && p2.first < m && p2.second >= 0 && p2.second < n && grid[p2.first][p2.second] == 1) {
                    q.push(p2);
                    grid[p2.first][p2.second] = 2;
                }
                if (p3.first >= 0 && p3.first < m && p3.second >= 0 && p3.second < n && grid[p3.first][p3.second] == 1) {
                    q.push(p3);
                    grid[p3.first][p3.second] = 2;
                }
                if (p4.first >= 0 && p4.first < m && p4.second >= 0 && p4.second < n && grid[p4.first][p4.second] == 1) {
                    q.push(p4);
                    grid[p4.first][p4.second] = 2;
                }
            }
        }
        return fresh ? -1 : cnt;
    }
private:
    using point = pair<int, int>;
    queue<point> q;
};