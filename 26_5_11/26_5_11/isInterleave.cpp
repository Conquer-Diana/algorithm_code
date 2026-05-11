#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//交错字符串
//给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。
//
//两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：
//
//s = s1 + s2 + ... + sn
//t = t1 + t2 + ... + tm
//| n - m| <= 1
//交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
//注意：a + b 意味着字符串 a 和 b 连接。
//
//示例 1：
//输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//输出：true
//
//示例 2：
//输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//输出：false
//
//示例 3：
//输入：s1 = "", s2 = "", s3 = ""
//输出：true

//这题看似是三个字符串，但实则，第三个字符串的长度可以由前两个字符串确定下来
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        //这里如果长度之和！=s3.size()，直接返回
        if (m + n != s3.size())
            return false;
        //让下标从1开始，方便填表
        s1 = " " + s1, s2 = " " + s2, s3 = " " + s3;
        //dp[i][j]表示：s1字符串中的[0,i]区间中的子串，以及s2字符串中的[0,j]区间中的子串是否能拼接成s3中[0,i+j]区间的字符串
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        //初始化：空串具有研究意义，先把s1和s2都为空串的位置初始化为true
        dp[0][0] = true;
        //s1为空串，s2不为空串
        //按位对比s2和s3，相等为true，一旦有一位不相等，直接break
        for (int j = 1; j <= n; j++)
        {
            if (s2[j] == s3[j])
                dp[0][j] = true;
            else
                break;
        }

        //s2为空串，s1不为空串
        //按位对比s1和s3，相等为true，一旦有一位不相等，直接break
        for (int i = 1; i <= m; i++)
        {
            if (s1[i] == s3[i])
                dp[i][0] = true;
            else
                break;
        }

        //状态转移方程：s1和s2要能拼接成s3，s3的结尾字符（即i+j）必须与s1的结尾字符（i）或者s2的结尾字符（j）其中之一相等
        //如果s1[i] == s3[i + j]，则看s1 [0,i-1] 与s2 [0,j]能否拼接成s3 [0,i+j-1]
       // 如果s2[j] == s3[i + j]，则看s2[0, j - 1] 与s1[0, i]能否拼接成s3 [0, i + j - 1]

        //填表顺序：从上往下，从左往右
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) || (s2[j] == s3[i + j] && dp[i][j - 1]);

        //根据状态表示，返回s1和s2结尾字符位置的dp值
        return dp[m][n];
    }
};