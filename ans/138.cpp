/**
 * @brief 138 - Copy List with Random Pointer
 * @link https://leetcode.cn/problems/copy-list-with-random-pointer/
 * @author !EEExp3rt
 * @date 2025-03-13
 * @note 参考了提示，使用交叉链表，首先沿着 next 把每个节点的复制节点先创建好，并且把每个原节点的 next 指向这些新创建的节点，新创建的节点的 next 再指向原链表的下一个节点，然后再从头到尾，检查每个原节点的 random ，如果 random 有内容就把他们对应的复制节点的 random 指向这个 random 所指的下一个节点（即random指向的原节点的复制节点），最后再把这个交叉链表拆开来，恢复原样，同时返回新创建的链表
 */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *cur = head; // Moves through the original list.
        Node *dummy = new Node(0); // Dummy node for the new list.
        // Create a interweaved list by moving through `next` pointer.
        // A    ->    B    ->    C    ->    D    ->    ...
        // A -> A' -> B -> B' -> C -> C' -> D -> D' -> ...
        while (cur) {
            Node *node = new Node(cur->val); // Create a new node A'.
            node->next = cur->next; // A' -> B
            cur->next = node; // A -> A'
            cur = node->next; // A change to B
        }
        // Add dummy node to the new list.
        dummy->next = head->next;
        // Handle the `random` pointer.
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next; // If A -> X, then A' -> X'.
            cur = cur->next->next;
        }
        // Handle the `next` pointer.
        cur = head; // Current original node.
        Node *next = cur->next->next; // Next original node.
        while (next) {
            cur->next->next = next->next; // A' -> B'
            cur->next = next; // A -> B
            cur = next; // Change to next original node.
            next = next->next->next; // Change to next next original node.
        }
        // Handle the last node.
        cur->next->next = nullptr;
        cur->next = nullptr;
        return dummy->next;
    }
};