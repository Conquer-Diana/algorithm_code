#define _CRT_SECURE_NO_WARNINGS

#include <string>

using namespace std;

//最长回文子串
//给你一个字符串 s，找到 s 中最长的回文子串。
//
//示例 1：
//
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//
//示例 2：
//
//输入：s = "cbbd"
//输出："bb"

//中心扩展算法
class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, len = 0;//记录起始位置和回文串长度

        for (int i = 0; i < s.size(); i++)
        {
            //进行奇数项扩展（例如aba，bab）
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                --left;
                ++right;
            }
            if (right - left - 1 > len)//当长度大于len时才更新begin和len
            {
                len = right - left - 1;
                begin = left + 1;
            }

            //进行偶数项扩展（例如aa，bb）
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                --left;
                ++right;
            }
            if (right - left - 1 > len)
            {
                len = right - left - 1;
                begin = left + 1;
            }
        }

        return s.substr(begin, len);

    }
};