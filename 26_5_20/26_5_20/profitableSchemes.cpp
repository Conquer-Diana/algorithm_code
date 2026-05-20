#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//盈利计划
//集团里有 n 名员工，他们可以完成各种各样的工作创造利润。
//
//第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
//
//工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。
//
//有多少种计划可以选择？因为答案很大，所以 返回结果模 10 ^ 9 + 7 的值。
//
//示例 1：
//输入：n = 5, minProfit = 3, group = [2, 2], profit = [2, 3]
//输出：2
//解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
//总的来说，有两种计划。
//
//示例 2：
//输入：n = 10, minProfit = 5, group = [2, 3, 5], profit = [6, 7, 8]
//输出：7
//解释：至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
//有 7 种可能的计划：(0)，(1)，(2)，(0, 1)，(0, 2)，(1, 2)，以及(0, 1, 2) 。

class Solution_1 {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = profit.size();
        //dp[i][j][k]表示：从前i个任务中选，员工人数不超过j，总利润不低于k的前提下，所有的计划种数
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));

        //初始化：只用初始化i=0的情况，表示没有任务，同时也没有利润，k=0，这时的dp[0][j][0]=1（什么都不选）
        for (int j = 0; j <= n; j++)
            dp[0][j][0] = 1;

        //状态转移方程：
        //不选i：即dp[i-1][j][k]
        //选i：员工人数与01背包一样，由于是“不超过”，所以需要满足j>=group[i]
        //但总利润这里是“至少” “不低于”，这里是允许k - profit[i] < 0的，即k < profit[i],因为就说明当前位置的利润就已经比当前位置所要求的利润k大了，这是好事，越大越好
        //但此时k - profit[i] < 0，在数组中如何表示呢?考虑到当前位置的利润就已经比当前位置所要求的利润k大了，所以就从前面k是0开始，也等价于从负数开始，所以，dp[i][j][k]=dp[i-1][j-group[i]][max(0,k-profit[i])]

        //填表顺序：只需要保证i从小到大即可
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= minProfit; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= group[i - 1])
                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0, k - profit[i - 1])];

                    dp[i][j][k] %= (int)1e9 + 7;//数值可能很大，%=上1e9+7
                }
            }
        }
        //返回值：根据状态表示，返回从所有任务中选，员工人数不超过n，总利润不低于minProfit的所有计划数
        return dp[m][n][minProfit];
    }
};

//空间优化版（滚动数组，降维，改变填表顺序）
class Solution_2 {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = profit.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));

        for (int j = 0; j <= n; j++)
            dp[j][0] = 1;

        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= group[i - 1]; j--)
            {
                for (int k = minProfit; k >= 0; k--)
                {
                    dp[j][k] += dp[j - group[i - 1]][max(0, k - profit[i - 1])];
                    dp[j][k] %= (int)1e9 + 7;
                }
            }
        }
        return dp[n][minProfit];
    }
};