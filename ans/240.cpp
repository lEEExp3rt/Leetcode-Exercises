/**
 * @brief 240 - Search a 2D Matrix II
 * @link https://leetcode.cn/problems/search-a-2d-matrix-ii/
 * @author !EEExp3rt
 * @date 2025-03-09
 * @note 使用了二分查找，先查找行，再查找列，但是这样做反而不如直接暴力搜索快，天塌了
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        return search(matrix, target, 0, m - 1);
    }
private:
    int m, n;
    bool search(vector<vector<int>>& matrix, int target, int up, int down) {
        int up_ = up, down_ = down;
        if (matrix[up_][0] > target || matrix[down_][n - 1] < target) return false;
        while (up_ <= down_) {
            int mid = (up_ + down_) / 2;
            cout << up_ << " " << mid << " " << down_ << endl;
            if (matrix[mid][0] == target || matrix[mid][n - 1] == target) return true;
            else if (matrix[mid][0] > target) down_ = mid - 1;
            else if (matrix[mid][n - 1] < target) up_ = mid + 1;
            else {
                vector<int> row = matrix.at(mid);
                if (find(row.begin(), row.end(), target) != row.end()) return true;
                if (mid > up && search(matrix, target, up, mid - 1)) return true;
                if (mid < down && search(matrix, target, mid + 1, down)) return true;
                return false;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                   {2, 5, 8, 12, 19},
                                   {3, 6, 9, 16, 22},
                                   {10, 13, 14, 17, 24},
                                   {18, 21, 23, 26, 30}};
    int target = 5;
    Solution solution;
    cout << solution.searchMatrix(matrix, target) << endl;
    return 0;
}