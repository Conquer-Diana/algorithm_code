#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//零钱兑换
//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 - 1。
//
//你可以认为每种硬币的数量是无限的。——这句话就说明了，这道题是一个完全背包问题
//
//示例 1：
//输入：coins = [1, 2, 5], amount = 11
//输出：3
//解释：11 = 5 + 5 + 1
//
//示例 2：
//输入：coins = [2], amount = 3
//输出： - 1
//
//示例 3：
//输入：coins = [1], amount = 0
//输出：0
//
//示例 4：
//输入：coins = [1], amount = 1
//输出：1
//
//示例 5：
//输入：coins = [1], amount = 2
//输出：2

class Solution_1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //参照完全背包的状态表示（从前i个物品中选，在总体积不超过j的前提下，背包中物品的最大价值），本题的dp[i][j]表示：从前i个物品中选，在总硬币面值恰好等于j的前提下，所有组合中最小的硬币个数
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        //初始化：由于本题是取最小硬币个数，要使第一行除（0，0）的位置，表示：没有硬币，但要凑成硬币面值等于j这种做不到的情况，影响不到min(dp[i][j], dp[i][j - coins[i - 1]] + 1)的选择，所以将这种做不到的情况全部初始化为无穷大
        for (int i = 1; i <= amount; i++)
            dp[0][i] = 0x3f3f3f3f;

        //状态转移方程：
        //1.不选i：即dp[i-1][j]
        //2.选一个i：即当j>=v[i]时，dp[i-1][j-coins[i]]+1
        //3.选两个i：即当j>=2*v[i]时，dp[i-1][j-2*coins[i]]+2
        //以此类推
        //最后dp[i][j]=min(dp[i-1][j],dp[i-1][j-coins[i]]+1,dp[i-1][j-2*coins[i]]+2,......,dp[i-1][j-k*coins[i]]+k)
        //这里要做优化，不做优化就是三层循环，即将选k个i这好几个状态，用一个状态表示
        //这里发现，dp[i][j-coins[i]]=min(dp[i-1][j-coin[i]],dp[i-1][j-2*coins[i]]+1,dp[i-1][j-3*coins[i]]+2,......,dp[i-1][j-x*coins[i]]+(x-1))
        //等式两边加上1,dp[i][j-coins[i]]+1=min(dp[i-1][j-coins[i]]+1,dp[i-1][j-2*coins[i]]+2,dp[i-1][j-3*coins[i]]+3,......,dp[i-1][j-x*coins[i]]+x)
        //即dp[i][j-coins[i]]+1就可以表示dp[i][j]中除了dp[i-1][j]的其余所有状态
        //所以dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i]]+1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])//由于做不到的情况初始化为了无穷大，所以这里就不用特判dp[i][j - coins[i - 1]]!=-1(之前规定的做不到的值）
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }

        //返回值：根据状态表示：返回所有硬币里选，总面值等于amount的dp值，由于可能>=无穷大，所以这种情况返回-1
        return (dp[n][amount] >= 0x3f3f3f3f ? -1 : dp[n][amount]);
    }
};

//空间优化版（降维，滚动数组）
class Solution_2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1);

        for (int i = 1; i <= amount; i++)
            dp[i] = 0x3f3f3f3f;

        for (int i = 1; i <= n; i++)
            //完全背包空间优化填表顺序从左往右
            for (int j = coins[i - 1]; j <= amount; j++)
                dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);

        return (dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount]);
    }
};