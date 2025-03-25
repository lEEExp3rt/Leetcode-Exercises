/**
 * @brief 79 - Word Search
 * @link https://leetcode.cn/problems/word-search/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 直接一个图的深度优先搜索，并且添加了很多的剪枝条件，比如每次只判断当前这个字符是否和目标单词中的对应位置字符相等，如果不相等那么后续直接全部剪枝即可，如果相等就继续搜索
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        bool flag = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) flag = dfs(board, word, 1, i, j);
                if (flag) return true;
            }
        }
        return false;
    }
private:
    vector<vector<bool>> visited;
    int n, m;
    bool dfs(vector<vector<char>>& board, string word, int len, int i, int j) {
        if (visited[i][j]) return false; // Visited.
        bool equal = word[len - 1] == board[i][j];
        if (!equal) return false;
        if (len == word.size()) return true; // Stop recursion.
        visited[i][j] = true; // Current node is visited.
        char c = board[i][j];
        // Left.
        if (i > 0 && dfs(board, word, len + 1, i - 1, j)) return true;
        // Right.
        if (i < n - 1 && dfs(board, word, len + 1, i + 1, j)) return true;
        // Up.
        if (j > 0 && dfs(board, word, len + 1, i, j - 1)) return true;
        // Down.
        if (j < m - 1 && dfs(board, word, len + 1, i, j + 1)) return true;
        visited[i][j] = false;
        return false;
    }
};