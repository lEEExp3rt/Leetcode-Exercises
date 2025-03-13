/**
 * @brief 148 - Sort List
 * @link https://leetcode.cn/problems/sort-list/
 * @author !EEExp3rt
 * @date 2025-03-13
 * @note 直接用一个有序字典强势摧毁，伟大无需多言！！！实际上这题如果要实现时间复杂度为 O(n log n) 和空间复杂度为 O(1) 的话需要实现一个归并排序，但是基于链表的实现过于麻烦了
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        multimap<int, ListNode*> mp;
        ListNode *node = head, *next = node->next;
        while (node) {
            next = node->next;
            node->next = nullptr;
            mp.insert({node->val, node});
            node = next;
        }
        ListNode *dummy = new ListNode();
        node = dummy;
        for (auto [_, n]: mp) {
            node->next = n;
            node = n;
        }
        return dummy->next;
    }
};