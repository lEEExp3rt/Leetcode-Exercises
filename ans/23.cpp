/**
 * @brief 23 - Merge k Sorted Lists
 * @link https://leetcode.cn/problems/merge-k-sorted-lists/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 简单易懂的方法，取两个链表直接进行合并，然后把这两个链表从原 vector 中弹出，把新合并的链表插入，直到都合并完成
 * @note 二编：这就是官方题解的顺序合并法
 * @note 三编：每个链表维护一个优先队列，然后每次取最小的节点，插入到新链表中，直到所有链表都为空
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            ListNode *l1 = lists.back();
            lists.pop_back();
            ListNode *l2 = lists.back();
            lists.pop_back();
            lists.push_back(mergeTwoLists(l1, l2));
        }
        return lists.at(0);
    }
private:
    /**
     * @brief Merge two sorted lists.
     * @param l1 The first list.
     * @param l2 The second list.
     * @return The merged list.
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *node1 = l1, *node2 = l2;
        ListNode *dummy = new ListNode(), *node = dummy;
        while (node1 && node2) {
            if (node1->val < node2->val) {
                node->next = node1;
                node1 = node1->next;
            } else {
                node->next = node2;
                node2 = node2->next;
            }
            node = node->next;
        }
        while (node1) {
            node->next = node1;
            node = node->next;
            node1 = node1->next;
        }
        while (node2) {
            node->next = node2;
            node = node->next;
            node2 = node2->next;
        }
        return dummy->next;
    }
};