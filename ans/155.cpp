/**
 * @brief 155 - Min Stack
 * @link https://leetcode.cn/problems/min-stack/
 * @author !EEExp3rt
 * @date 2025-04-02
 * @note 一个 vector + map 搞定所有
 * @note 二编：用一个辅助栈来存储最小值，每次 push 和 pop 与原栈同步，这样弹出时，最小值仍在栈内，就可以用 getMin() 直接返回最小元素
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() : size(0) {}
    
    void push(int val) {
        stk.push_back(val);
        size++;
        mp[val]++;
    }
    
    void pop() {
        int topValue = stk[size - 1];
        mp[topValue]--;
        if (!mp[topValue]) mp.erase(topValue);
        stk.pop_back();
        size--;
    }
    
    int top() {
        return stk.at(size - 1);
    }
    
    int getMin() {
        return mp.begin()->first;
    }
private:
    vector<int> stk;
    map<int, int> mp;
    int size;
};