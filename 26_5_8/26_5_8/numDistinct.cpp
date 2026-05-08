#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//不同的子序列
//给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
//
//测试用例保证结果在 32 位有符号整数范围内。
//
//示例 1：
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//"ra""b"bb"it"
//"ra"b"b"b"it"
//"ra"bb"b""it"
//
//示例 2：
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
//“ba”b“g”bag
//“ba”bgba“g”
//ba“b”gb“ag”
//“b”abgb“ag”
//babg“bag”

//此题难在状态表示
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        //dp[i][j]表示：s字符串中[0,j]区间内所有的子序列中，有多少个t字符串中[0，i]内的子串（注意：s中区间表示的是子序列，而t中表示的是子串）

        //初始化：这时候空串又发挥作用了，多开一行和多开一列，对填表很大的方便
        vector<vector<double>> dp(m + 1, vector<double>(n + 1));
        //当t中有空串时，s中也能在其中找到空串对应，出现次数为1次
        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;

        //当s中有空串，t不为空串时，这时s中找不到t，所以出现次数为0
        //for(int i=1;i<=m;i++)
            //dp[i][0]=0;

        //将两个字符串前面加上空格，与dp表对应
        t = ' ' + t;
        s = ' ' + s;

        //状态转移方程：分为子序列中包含s[j]与不包含s[j]两种情况
        //包含s[j]：此情况的前提是,t[i]==s[j]，此时dp[i][j]等于dp[i-1][j-1]
        //不包含s[j]：此情况是一定发生的，此时dp[i][j]等于dp[i][j-1]
        // 这两种情况不会出现重复统计的情况，因为，t是子串，一个以i-1结尾，一个以i结尾（必须包含，不像s是子序列，可以不包含）
        //最后的dp[i][j]等于上述两种情况的和（如果包含s[j]的情况存在的情况下）

        //填表顺序：填dp[i][j]时，可能需要dp[i][j - 1]，dp[i - 1][j - 1]，即左边和左上，所以从上往下填，从左往右填
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] += dp[i][j - 1];
                if (t[i] == s[j])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        //返回两个字符串最后位置的dp值
        return dp[m][n];
    }
};