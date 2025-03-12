/**
 * @brief 2 - Add Two Numbers
 * @link https://leetcode.cn/problems/add-two-numbers/
 * @author !EEExp3rt
 * @date 2025-03-12
 * @note 轻松拿下
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head1 = l1, *head2 = l2;
        ListNode *sum = new ListNode(), *head = sum;
        while (head1 && head2) {
            int value = head1->val + head2->val + carry;
            carry = value > 9;
            ListNode *node = new ListNode(value % 10);
            sum->next = node;
            sum = sum->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1) {
            int value = head1->val + carry;
            carry = value > 9;
            ListNode *node = new ListNode(value % 10);
            sum->next = node;
            sum = sum->next;
            head1 = head1->next;
        }
        while (head2) {
            int value = head2->val + carry;
            carry = value > 9;
            ListNode *node = new ListNode(value % 10);
            sum->next = node;
            sum = sum->next;
            head2 = head2->next;
        }
        if (carry) {
            ListNode *node = new ListNode(1);
            sum->next = node;
        }
        return head->next;
    }
};