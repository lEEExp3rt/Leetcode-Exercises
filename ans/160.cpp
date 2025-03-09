/**
 * @brief 160 - Intersection of Two Linked Lists
 * @link https://leetcode.cn/problems/intersection-of-two-linked-lists/
 * @author !EEExp3rt
 * @date 2025-03-09
 * @note 双指针法，若 len(A) = a + c， len(B) = b + c，那么两个指针都走 a + b + c 后肯定相遇，如果此时还没相遇就不会交叉，记得判断初始条件
 * @note 二编：网友神奇题解，因为题目给了所有的节点值都是正数，所以先走一遍 A 并把所有节点都取负，然后再走一遍 B，如果遇到负值说明这个节点就是交叉节点，妙哉妙哉
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == headB) return headA;
        ListNode *pa = headA, *pb = headB;
        int len = 0;
        for (; pa; len++) pa = pa->next;
        for (; pb; len++) pb = pb->next;
        ListNode *target = nullptr;
        pa = headA, pb = headB;
        for (int i = 0; i < len; i++) {
            pa = pa->next ? pa->next : headB;
            pb = pb->next ? pb->next : headA;
            if (pa == pb) {
                target = pa;
                break;
            }
        }
        return target;
    }
};