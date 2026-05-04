#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//最长回文子串
//给你一个字符串 s，找到 s 中最长的 回文 子串。
//
//示例 1：
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//
//示例 2：
//输入：s = "cbbd"
//输出："bb"

//与《回文子串》判断回文串的dp思路一样
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        //记录最长回文子串的长度和起始位置
        int begin = 0, len = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;

                //每次取最长回文子串更新len和begin
                if (dp[i][j] && j - i + 1 > len)
                {
                    len = j - i + 1;
                    begin = i;
                }
            }
        }
        //返回最长回文子串
        return s.substr(begin, len);
    }
};