/**
 * @brief 25 - Reverse Nodes in k-Group
 * @link https://leetcode.cn/problems/reverse-nodes-in-k-group/
 * @author !EEExp3rt
 * @date 2025-03-12
 * @note 真尼玛不容易我草，写了一晚上了，终于写出来了，用时 0ms 击败 100%；总体来说，思路并不复杂，但是实现起来有点麻烦，主要考虑一个：把一个链表用迭代法逆转，然后在此基础上，保持一组链表的入节点和出节点，把中间的节点全部逆转，入节点接到逆转后的头节点上，新的尾节点接到出节点上，然后扫描每个组，满足个数就逆转，否则不逆转
 * @note 写了一个题解：https://leetcode.cn/problems/reverse-nodes-in-k-group/solutions/3609127/k-ge-yi-zu-fan-zhuan-lian-biao-by-1eeexp-qguy/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head); // Dummy node before the head.
        ListNode *pre = dummy, *tail = dummy->next; // pre: the node before the head of one group; tail: the one after the tail of one group.
        int len = 0;
        while (tail) {
            len++;
            tail = tail->next;
            if (len % k == 0) { // A group is found.
                pre = reverse(pre, tail); // Reverse the group.
                tail = pre->next; // Update the tail and pre.
            }
        }
        return dummy->next; // Return the head of the list.
    }
private:
    /**
     * @brief Reverse a group of nodes between `in` and `out`.
     * @param in The node before the head of the group.
     * @param out The node after the tail of the group.
     * @return The last node of the group.
     */
    ListNode* reverse(ListNode *in, ListNode *out) {
        ListNode *node1 = nullptr, *node2 = in->next, *tail = out;
        // Every time reverse one node, remove the old pointer to the next one and add a new one.
        while (node2 != out) {
            node1 = node2;
            node2 = node2->next;
            node1->next = tail;
            tail = node1;
        }
        ListNode *last = in->next;
        in->next = node1;
        return last;
    }
};