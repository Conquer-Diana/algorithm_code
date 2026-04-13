#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//
//问总共有多少条不同的路径？
//
//示例 1：
//输入：m = 3, n = 7
//输出：28
//
//示例 2：
//输入：m = 3, n = 2
//输出：3
//解释：
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右->向下->向下
//2. 向下->向下->向右
//3. 向下->向右->向下
//
//示例 3：
//输入：m = 7, n = 3
//输出：28
//
//示例 4：
//输入：m = 3, n = 3
//输出：6

//解法一：记忆化搜索
class Solution_1 {
    int memo[101][101];
public:
    int uniquePaths(int m, int n) {
        memset(memo, -1, sizeof(memo));
        return dfs(m, n);
    }

    int dfs(int m, int n)
    {
        //进递归前先看看备忘录
        if (memo[m][n] != -1)
            return memo[m][n];

        //递归出口：当m-1或者n-1等于0时，算越界，所以返回0
        if (m == 0 || n == 0)
        {
            memo[m][n] = 0;
            return memo[m][n];
        }

        //递归出口：在起点返回1
        if (m == 1 && n == 1)
        {
            memo[m][n] = 1;
            return memo[m][n];
        }

        //自顶向下：到一个点，只能从他的上方或者左边到达，所以路径总数就是这两个方向加起来
        memo[m][n] = dfs(m - 1, n) + dfs(m, n - 1);
        return memo[m][n];
    }
};

//解法二：动态规划，由记忆化搜索变化来的
class Solution_2 {
    int dp[101][101];
public:
    int uniquePaths(int m, int n) {
        //初始化
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        for (int j = 1; j <= n; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                //不能把初始化好的起点覆盖掉
                if (i != 1 || j != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m][n];
    }
};