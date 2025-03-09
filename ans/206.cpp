/**
 * @brief 206 - Reverse Linked List
 * @link https://leetcode.cn/problems/reverse-linked-list/
 * @author !EEExp3rt
 * @date 2025-03-09
 * @note 无需多言
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;
        ListNode *p = head;
        while (p) {
            ListNode* node = new ListNode(p->val, ans);
            ans = node;
            p = p->next;
        }
        return ans;
    }
};