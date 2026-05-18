#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//零钱兑换 II
//给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
//
//请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
//
//假设每一种面额的硬币有无限个。
//
//题目数据保证结果符合 32 位带符号整数。
//
//示例 1：
//
//输入：amount = 5, coins = [1, 2, 5]
//输出：4
//解释：有四种方式可以凑成总金额：
//5 = 5
//5 = 2 + 2 + 1
//5 = 2 + 1 + 1 + 1
//5 = 1 + 1 + 1 + 1 + 1
//
//示例 2：
//输入：amount = 3, coins = [2]
//输出：0
//解释：只用面额 2 的硬币不能凑成总金额 3 。
//
//示例 3：
//输入：amount = 10, coins = [10]
//输出：1

//只是《零钱兑换_1》那道题换一个问法
class Solution_1 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //dp[i][j]表示：从前i个硬币开始选，在总金额恰好等于j的前提下，所有硬币的选法
        vector<vector<double>> dp(n + 1, vector<double>(amount + 1));
        //初始化，老规矩，只初始化第一行，（0，0）位置表示没有硬币，但是总金额恰好为0，选法为1种，其余位置，没有对应选法，为0
        dp[0][0] = 1;

        //状态转移方程：
        //1.不选i，dp[i-1][j]
        //2.选1个i，dp[i-1][j-coins[i]] （j>=coins[i])
        //3.选2个i，dp[i-1][j-2*coins[i]] （j>=2*coins[i])
        //...与完全背包一样，最后优化后，情况2以后可以用dp[i][j-coins[i]]来表示（j>=coins[i])
        //所以最后dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];

        //填表顺序：从上至下，从左向右
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }

        //返回值：根据状态表示，返回从所有硬币中选，总金额等于amount的所有选法数
        return dp[n][amount];
    }
};

//空间优化版
//滚动数组，降维
class Solution_2 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<double> dp(amount + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = coins[i - 1]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i - 1]];
            }
        }

        return dp[amount];
    }
};