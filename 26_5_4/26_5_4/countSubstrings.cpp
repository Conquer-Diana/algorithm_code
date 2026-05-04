#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//回文子串
//给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
//
//回文字符串 是正着读和倒过来读一样的字符串。
//
//子字符串 是字符串中的由连续字符组成的一个序列。
//
//示例 1：
//输入：s = "abc"
//输出：3
//解释：三个回文子串 : "a", "b", "c"
//
//示例 2：
//输入：s = "aaa"
//输出：6
//解释：6个回文子串 : "a", "a", "a", "aa", "aa", "aaa"

//回文串系列问题的敲门砖
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        //dp[i][j]代表：开头为i，末尾为j的子串是否为回文子串，存bool值
        vector<vector<bool>> dp(n, vector<bool>(n));

        int ret = 0;
        //填表顺序：从下往上填（因为填dp[i][j]时，需要dp[i+1][j-1]
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] != s[j])
                    dp[i][j] = false;
                //当s[i] == s[j]时，分为三种情况
                else
                {
                    //一个元素
                    if (i == j)
                        dp[i][j] = true;
                    //两个相等的元素
                    else if (i + 1 == j)
                        dp[i][j] = true;
                    //i+1<j，说明要判断中间是否为回文串[i+1,j-1]
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                //最后结果为dp中true的个数
                if (dp[i][j])
                    ret++;
            }
        }
        return ret;
    }
};