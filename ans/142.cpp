/**
 * @brief 142 - Linked List Cycle II
 * @link https://leetcode.cn/problems/linked-list-cycle-ii/
 * @author !EEExp3rt
 * @date 2025-03-11
 * @note 参考题解，我想的也是快慢指针，并且尝试寻找数学关系，但是没有找到，原因是快慢指针相遇时，慢指针在环内走了一圈不到，而快指针可能已经走了很多圈了
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        int cnt = 1;
        while (slow && fast && cnt++ < 10000) {
            if (slow == fast) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
            if (!slow->next || !fast->next || !fast->next->next) return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};