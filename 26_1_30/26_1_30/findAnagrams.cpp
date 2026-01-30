#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//找到字符串中所有的字母异位词
//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//
//
//示例 1:
//
//输入: s = "cbaebabacd", p = "abc"
//输出 : [0, 6]
//解释 :
//	起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//	起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//	
//示例 2 :
//
//	输入 : s = "abab", p = "ab"
//	输出 : [0, 1, 2]
//	解释 :
//	起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//	起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//	起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。

//滑动窗口+哈希表

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26];
        int hash2[26];
        vector<int> ret;

        for (int i = 0; i < p.size(); i++)
           hash1[p[i] - 'a']++;

        int left = 0;
        int right = 0;

        while (right < s.size())
        {
            hash2[s[right] - 'a']++;

            while (right - left + 1 > p.size())//由于本题的窗口大小是固定的，所以right走一步，left走一步，这里可以用if
            {
                hash2[s[left++] - 'a']--;
            }

            if (right - left + 1 == p.size())
            {
                int k = 0;
                for (k = 0; k < p.size(); k++)
                {
                    if (hash1[p[k] - 'a'] != hash2[p[k] - 'a'])//判断26个字母中，两个hash表中的数目相不相等
                        break;
                }
                if (k == p.size())
                    ret.push_back(left);
            }

            right++;
        }

        return ret;
    }
};

//判断两个hash表数目是否相等那一步，可以做一个小优化
//可以维护一个count变量，代表有效字符数目

class Solution_better {
public:
    vector<int> findAnagrams(string s, string p) {
        int hash1[26];
        int hash2[26];

        for (int i = 0; i < p.size(); i++)
            hash1[p[i] - 'a']++;

        int left = 0;
        int right = 0;
        int count = 0;
        vector<int> ret;

        while (right < s.size())
        {
            hash2[s[right] - 'a']++;

            //进窗口时，如果hash2中的该字符数量小于等于hash1中的数量，则count++
            if (hash2[s[right] - 'a'] <= hash1[s[right] - 'a'])
                count++;

            while (right - left + 1 > p.size())
            {
                //出窗口前，先判断如果hash2中的该字符数量小于等于hash1中的数量，则count--
                if (hash2[s[left] - 'a'] <= hash1[s[left] - 'a'])
                    count--;

                hash2[s[left++] - 'a']--;
            }

            //最后更新结果时判断count等不等于p.size()即可
            if (right - left + 1 == p.size() && count == p.size())
                ret.push_back(left);

            right++;
        }

        return ret;
    }
};