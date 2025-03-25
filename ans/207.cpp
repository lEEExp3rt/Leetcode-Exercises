/**
 * @brief 207 - Course Schedule
 * @link https://leetcode.cn/problems/course-schedule/
 * @author !EEExp3rt
 * @date 2025-03-19
 * @note 原来我的思路和题解没有差很多，本质上说是一样的，我是判断拓扑序有没有存在环，但是考虑漏了对“已遍历”节点的判断条件，所以导致实际上是遍历整个图很多次去找有没有环，而实际上按照题解是做法就是找到一个拓扑序就好了，不用去找所有的环
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        order = vector<vector<int>>(numCourses, vector<int>(1, -1)); // Prerequisites.
        checked = vector<int>(numCourses, 0);
        unordered_set<int> noPrevs; // Courses without prerequisites.
        // Parse the prerequisites.
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int>& v = prerequisites.at(i);
            int next = v[0], prev = v[1];
            if (next == prev) return false;
            if (order[next][0] == -1) order[next][0] = prev;
            else order[next].push_back(prev);
            noPrevs.insert(next);
            noPrevs.erase(prev);
        }
        // Check all path.
        for (const int& course: noPrevs) {
            if (!check(course)) return false;
        }
        return true;
    }
private:
    vector<vector<int>> order;
    vector<int> checked;
    bool check(int index) {
        if (order[index][0] == -1) return true;
        if (checked[index] == 1) return false;
        else if (checked[index] == 2) return true;
        vector<int>& prevs = order[index];
        checked[index] = true;
        for (const int& prev: prevs) {
            if (!check(prev)) return false;
        }
        checked[index] = 2;
        return true;
    }
};