/**
 * @brief 24 - Swap Nodes in Pairs
 * @link https://leetcode.cn/problems/swap-nodes-in-pairs/
 * @author !EEExp3rt
 * @date 2025-03-12
 * @note 注意这一组节点和前一个节点后一个节点这四点的关系，指针拆来拆去，以及边界条件判断
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *node1 = head, *node2 = dummy;
        while (node1 && node1->next) {
            ListNode *tmp = node1->next;
            node2->next = tmp;
            node1->next = tmp->next;
            tmp->next = node1;
            node2 = node1;
            node1 = node2->next;
        }
        return dummy->next;
    }
};