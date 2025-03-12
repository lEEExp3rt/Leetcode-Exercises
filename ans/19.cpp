/**
 * @brief 19 - Remove Nth Node From End of List
 * @link https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * @author !EEExp3rt
 * @date 2025-03-12
 * @note 第一个指针先从头开始走 n 步，然后第二个指针也从头开始走，二者之后同步，如果第一个指针到达末尾，那么此时第二个指针的下一个节点就需要删除；需要注意的是如果删除的节点是头结点则需要特殊考虑以下
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail = head;
        for (int i = 0; i < n; i++) tail = tail->next;
        if (!tail) return head->next;
        ListNode *prev = head;
        while (tail->next) {
            tail = tail->next;
            prev = prev->next;
        }
        ListNode *node = prev->next;
        prev->next = node->next;
        node->next = nullptr;
        delete node;
        return head;
    }
};