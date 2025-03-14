/**
 * @brief 146 - LRU Cache
 * @link https://leetcode.com/problems/lru-cache/
 * @author !EEExp3rt
 * @date 2025-03-14
 * @note 干就完了，用一个哈希表存一下节点，然后LRU缓存用一个list实现，每次更新时就把节点提到链表首位，移除时就把链表末尾移除
 * @note 二编：看了题解和评论区，题目的意思应该是需要手搓这个链表，所以链表的题目总体来说难度不大，就是实现起来非常麻烦恶心
 */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        lru = list<kv>(capacity);
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        node it = cache.at(key);
        int value = it->second;
        lru.erase(it);
        lru.push_front({key, value});
        cache[key] = lru.begin();
        return value;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            node it = cache.at(key);
            lru.erase(it);
        } else {
            node it = --lru.end();
            cache.erase(it->first);
            lru.erase(it);
        }
        lru.push_front({key, value});
        cache[key] = lru.begin();
    }
private:
    using kv = pair<int, int>;
    using node = list<kv>::iterator;
    unordered_map<int, node> cache;
    list<kv> lru;
};