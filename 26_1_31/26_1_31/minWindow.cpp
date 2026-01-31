#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//最小覆盖字串
//给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。
//如果 s 中存在多个符合条件的子字符串，返回任意一个。
//
//注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
//
//示例 1：
//
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//解释：最短子字符串 "BANC" 包含了字符串 t 的所有字符 'A'、'B'、'C'
//
//示例 2：
//
//输入：s = "a", t = "a"
//输出："a"
//
//示例 3：
//
//输入：s = "a", t = "aa"
//输出：""
//解释：t 中两个字符 'a' 均应包含在 s 的子串中，因此没有符合条件的子字符串，返回空字符串。

//滑动窗口+unordered_map容器
//使用count表示字符串t中的字母种类
class Solution_Unordered_Map {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash1, hash2;

        for (auto n : t)
            hash1[n]++;

        int left = 0;
        int right = 0;
        int count = 0;
        int len = INT_MAX;
        int begin = -1;

        while (right < s.size())
        {
            hash2[s[right]]++;

            //使用unordered_map必须注意，不在t中的字母，判断时也会加入键值，value为0
            if (hash1.count(s[right]) && hash2[s[right]] == hash1[s[right]])
                count++;

            //由于此题，内循环条件需要判断hash1的size，所以前面维护count值的判断前，必须先判断hash1中是否有该字母
            while (count == hash1.size())
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }

                //此处判断也一样
                if (hash1.count(s[left]) && hash2[s[left]] == hash1[s[left]])
                    count--;
                hash2[s[left++]]--;
            }

            right++;
        }

        if (begin == -1) return "";
        else return s.substr(begin, len);
    }
};

//使用数组来模拟hash表版本
class Solution_Array {
public:
    string minWindow(string s, string t) {
        int hash1[128] = { 0 };
        int hash2[128] = { 0 };
        int kinds = 0;

        for (auto n : t)
            if (hash1[n]++ == 0)
                kinds++;//需要单独计算里面具体字母的种类个数

        int left = 0;
        int right = 0;
        int count = 0;
        int len = INT_MAX;
        int begin = -1;

        while (right < s.size())
        {
            hash2[s[right]]++;

            if (hash2[s[right]] == hash1[s[right]])
                count++;

            while (count == kinds)
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }

                if (hash2[s[left]] == hash1[s[left]])
                    count--;
                hash2[s[left++]]--;
            }

            right++;
        }

        if (begin == -1) return "";
        else return s.substr(begin, len);
    }
};