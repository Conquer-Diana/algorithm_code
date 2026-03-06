#define _CRT_SECURE_NO_WARNINGS

#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

//字母异位词分组
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//
//示例 1:
//
//输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
//
//输出 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
//
//解释：
//
//在 strs 中没有字符串可以通过重新排列来形成 "bat"。
//字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
//字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。

//体现容器的强大之处，存排序后的string，和字符串数组
//每个string按ASCII码排序之后作为key，将之前未排序的string插入字符串数组
//最后遍历哈希表，合并所有字符串数组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for (int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            hash[strs[i]].push_back(tmp);
        }

        vector<vector<string>> ret;
        for (auto& kv : hash)
            ret.push_back(kv.second);

        return ret;
    }
};