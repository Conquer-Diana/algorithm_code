#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//斐波那契数
//解法一：正常递归
class Solution_1 {
public:
    int fib(int n) {
        return dfs(n);
    }
    int dfs(int n)
    {
        if (n == 0 || n == 1)
            return n;

        return dfs(n - 1) + dfs(n - 2);
    }
};

//解法二：记忆化搜索（带备忘录的递归）
class Solution_2 {
    int memo[31];
public:
    int fib(int n) {
        memset(memo, -1, sizeof(memo));//需要先将备忘录初始化为递归中从未出现的数
        return dfs(n);
    }

    int dfs(int n)
    {
        //每次递归前，都先到备忘录里看一看
        if (memo[n] != -1)
            return memo[n];

        if (n == 0 || n == 1)
        {
            memo[n] = n;
            return memo[n];
        }

        memo[n] = dfs(n - 1) + dfs(n - 2);
        return memo[n];
    }
};

//解法三：动态规划
class Solution_3 {
    int dp[101];
public:
    int fib(int n) {
        int mod = (int)1e9 + 7;
        dp[0] = 0, dp[1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

        return dp[n];
    }
};

