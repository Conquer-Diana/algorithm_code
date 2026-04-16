#define _CRT_SECURE_NO_WARNINGS

//第N个泰波那契数
//泰波那契序列 Tn 定义如下：
//
//T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn + 3 = Tn + Tn + 1 + Tn + 2
//
//给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
//
//示例 1：
//
//输入：n = 4
//输出：4
//解释：
//T_3 = 0 + 1 + 1 = 2
//T_4 = 1 + 1 + 2 = 4
//
//示例 2：
//
//输入：n = 25
//输出：1389537

//解法一：动态规划
class Solution_1 {
    int dp[38];//状态表示为第i个泰波那契数
public:
    int tribonacci(int n) {
        dp[0] = 0, dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

        return dp[n];
    }
};

//解法二：滚动数组版——以后多用于背包问题中
class Solution_2 {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int a = 0, b = 1, c = 1, d = 0;

        for (int i = 3; i <= n; i++)
        {
            d = a + b + c;
            //注意赋值顺序
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};