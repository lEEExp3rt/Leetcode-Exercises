/**
 * @brief 141 - Linked List Cycle
 * @link https://leetcode.cn/problems/linked-list-cycle/
 * @author !EEExp3rt
 * @date 2025-03-11
 * @note 快慢指针
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        int cnt = 0;
        while (slow && fast && cnt < 10000) {
            if (slow == fast) return true;
            if (!slow->next) return false;
            if (!fast->next || !fast->next->next) return false;
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }
        return false;
    }
};