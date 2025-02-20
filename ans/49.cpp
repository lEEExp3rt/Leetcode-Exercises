/**
 * @brief 49 - Group Anagrams
 * @link https://leetcode.cn/problems/group-anagrams/
 * @author !EEExp3rt
 * @date 2025-02-20
 * @note 把字符串序列化为字典序，然后用哈希表存储，同时在遍历原输入列表时，将序列化后的字符串作为键，原字符串作为值存储在哈希表中
 */

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> dict;
        for (std::string str: strs) {
            std::string seq = serialization(str);
            if (!dict.count(seq)) {
                std::vector<std::string> items;
                items.push_back(str);
                dict[seq] = items;
            } else {
                dict[seq].push_back(str);
            }
        }

        std::vector<std::vector<std::string>> ans;
        ans.reserve(dict.size());
        for (auto pair: dict) {
            std::vector<std::string>& items = pair.second;
            ans.push_back(items);
        }
        return ans;
    }
private:
    std::string serialization(const std::string& input) {
        std::string output = input;
        std::sort(output.begin(), output.end());
        return output;
    }
};