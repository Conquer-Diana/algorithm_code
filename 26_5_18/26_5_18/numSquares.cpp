#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//完全平方数
//给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
//
//完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
//
//示例 1：
//输入：n = 12
//输出：3
//解释：12 = 4 + 4 + 4
//
//示例 2：
//输入：n = 13
//输出：2
//解释：13 = 4 + 9

//也是《零钱兑换_1》的孪生题，换了种表达
class Solution_1 {
public:
    int numSquares(int n) {
        //dp[i][j]表示:从前i个完全平方数开始选，在总和等于n的前提下，最小的选择数量
        //因为选择的完全平方数本身不可能大于n，所以i*i<=n，即i<=sqrt(n)
        vector<vector<int>> dp(sqrt(n) + 1, vector<int>(n + 1));

        //初始化：（0，0）位置为没有数可选，但总和为0，选择数量为0，其余位置不可能做到，而且这道题要取最小值，为了不受影响，全初始化为无穷大
        for (int i = 1; i <= n; i++)
            dp[0][i] = 0x3f3f3f3f;

        //状态转移方程：
        //1.不选i，dp[i-1][j]
        //2.选1个i，dp[i-1][j-i*i]+1 （j>=i*i)
        //3.选2个i，dp[i-1][j-2*i*i]+2 （j>=2*i*i)
        //...与完全背包一样，最后优化后，情况2以后可以用dp[i][j-i*i]+1来表示（j>=i*i)
        //所以最后dp[i][j]=min（dp[i-1][j]，dp[i][j-i*i]+1）;

        //填表顺序：从上至下，从左至右
        for (int i = 1; i <= sqrt(n); i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= i * i)
                    dp[i][j] = min(dp[i][j], dp[i][j - i * i] + 1);
            }
        }

        //返回值：返回从sqrt（n）中所以完全平方数中选，总和为n的最小选择数量
        return dp[sqrt(n)][n];
    }
};

//空间优化版
//滚动数组，降维
class Solution_2 {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
            dp[i] = 0x3f3f3f3f;

        for (int i = 1; i <= sqrt(n); i++)
            for (int j = i * i; j <= n; j++)
                dp[j] = min(dp[j], dp[j - i * i] + 1);

        return dp[n];
    }
};