/**
 * @brief 21 - Merge Two Sorted Lists
 * @link https://leetcode.cn/problems/merge-two-sorted-lists/
 * @author !EEExp3rt
 * @date 2025-03-12
 * @note 最简单的一集
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *head1 = list1, *head2 = list2;
        ListNode *merged = new ListNode(), *head = merged;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                ListNode *node = new ListNode(head1->val);
                merged->next = node;
                merged = merged->next;
                head1 = head1->next;
            } else {
                ListNode *node = new ListNode(head2->val);
                merged->next = node;
                merged = merged->next;
                head2 = head2->next;
            }
        }
        while (head1) {
            ListNode *node = new ListNode(head1->val);
            merged->next = node;
            merged = merged->next;
            head1 = head1->next;
        }
        while (head2) {
            ListNode *node = new ListNode(head2->val);
            merged->next = node;
            merged = merged->next;
            head2 = head2->next;
        }
        return head->next;
    }
};