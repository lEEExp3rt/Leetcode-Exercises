/**
 * @brief 56 - Merge Intervals
 * @link https://leetcode.cn/problems/merge-intervals/
 * @author !EEExp3rt
 * @date 2025-03-07
 * @note 轻松拿下，先对子区间按左标排序（使用一个map插入），然后顺序迭代经过排序的子区间，如果当前迭代的左标在经过处理的最后一个区间的中间，就合并进去，否则当前区间肯定无法和前面区间合并，就创建一个新的子区间，即先排序，再用结果的最后一个区间判断是否重叠，如果重叠，更改最后一个区间的右端点就行，没有就加入
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for (const vector<int>& interval: intervals) mp[interval[0]] = max(interval[1], mp[interval[0]]);
        vector<vector<int>> ans;
        map<int, int>::iterator it = mp.begin();
        ans.push_back(vector<int>{it->first, it->second});
        for (it++ ; it != mp.end(); it++) {
            int& r = ans[ans.size() - 1].at(1);
            if (r >= it->first) {
                r = max(it->second, r);
            } else {
                ans.push_back(vector<int>{it->first, it->second});
            }
        }
        return ans;
    }
};