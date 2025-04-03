/**
 * @brief 208 - Implement Trie (Prefix Tree)
 * @link https://leetcode.cn/problems/implement-trie-prefix-tree/
 * @author !EEExp3rt
 * @date 2025-04-03
 * @note 就是构造一个树
 * @note 二编：说实话和官方题解一毛一样的想法，不过前缀树确实是一种很牛逼的数据结构，又学会了一个~
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    vector<struct Node*> children;
    bool end;
    Node() : end(false), children(vector<struct Node*>(26, nullptr)) {}
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for (const char& ch : word) {
            if (!node->children[ch - 'a'])
                node->children[ch - 'a'] = new Node();
            node = node->children[ch - 'a'];
        }
        node->end = true;
        return ;
    }
    
    bool search(string word) {
        Node *node = root;
        for (const char& ch : word) {
            node = node->children[ch - 'a'];
            if (!node) return false;
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (const char& ch : prefix) {
            node = node->children[ch - 'a'];
            if (!node) return false;
        }
        return true;
    }
private:
    Node *root;
};