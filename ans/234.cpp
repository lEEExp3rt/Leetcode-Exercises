/**
 * @brief 234 - Palindrome Linked List
 * @link https://leetcode.cn/problems/palindrome-linked-list/
 * @author !EEExp3rt
 * @date 2025-03-10
 * @note 用字符串存储每一个数字，因为数字是 0 <= Node.val <= 9，所以可以直接转换为字符
 * @note 我原来的想法：因为题目说了要空间复杂度为 O(1)，加上题目说了每个节点的数值为 0 - 9，所以我想到用一个整数变量存储，这样只用判断这个整数是不是回文数就好了，但是谁知道链表有 10^5 次方个节点，所以这个方法不行，long long 也炸了
 * @note 二编：官方题解是快慢指针，炸了，拼尽全力无法战胜
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode* node = head;
        string s;
        int len = 0;
        while (node) {
            s += to_string(node->val);
            node = node->next;
            len++;
        }
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - i - 1]) return false;
        }
        return true;
    }
};