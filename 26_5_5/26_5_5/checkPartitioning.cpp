#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//分割回文串 IV
//给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。
//
//当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。
//
//示例 1：
//输入：s = "abcbdd"
//输出：true
//解释："abcbdd" = "a" + "bcb" + "dd"，三个子字符串都是回文的。
//
//示例 2：
//输入：s = "bcbddxy"
//输出：false
//解释：s 没办法被分割成 3 个回文子字符串。

//依旧是用《回文子串》的架构，先在dp表中存入所有子串是否为回文子串，再不断用i，j枚举s中的三元组，划分为三个部分[0,i-1],[i,j],[j+1,n-1]，三个部分同时为回文串时，即为true
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                    dp[i][j] = i + 1 < j ? dp[i + 1][j - 1] : true;
            }
        }

        for (int i = 1; i < n - 1; i++)
            for (int j = i; j < n - 1; j++)
                if (dp[0][i - 1] && dp[i][j] && dp[j + 1][n - 1])
                    return true;

        return false;
    }
};