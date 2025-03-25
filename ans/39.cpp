/**
 * @brief 39 - Combination Sum
 * @link https://leetcode.cn/problems/combination-sum/
 * @author !EEExp3rt
 * @date 2025-03-25
 * @note 回溯法轻松拿下，先对数组进行排序，起到一个剪枝的作用，然后注意一个就是为了避免产生的结果出现重复，每次迭代要设置一个起始索引，用这个索引来进行递归
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> tmp;
    int sum;
    void backtrace(vector<int>& candidates, int target, int base) {
        if (base == candidates.size()) return ;
        for (int i = base; i < candidates.size(); i++) {
            int num = candidates.at(i);
            if (sum + num > target) break;
            sum += num;
            tmp.push_back(num);
            if (sum == target) ans.push_back(tmp);
            else backtrace(candidates, target, i);
            sum -= num;
            tmp.pop_back();
        }
        return ;
    }
};