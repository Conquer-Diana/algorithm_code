#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//使用最小花费爬楼梯
//数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
//
//每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
//
//请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
//
//示例 1：
//
//输入：cost = [10, 15, 20]
//输出：15
//解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
//
//示例 2：
//
//输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
//输出：6
//解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。

//解法一：从左往右填表
//dp[i]表示当前位置的最小花费
class Solution_1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001];
        int n = cost.size();
        dp[0] = dp[1] = 0;

        for (int i = 2; i <= n; i++)
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);

        return dp[n];
    }
};

//解法二：从右往左填表
//dp[i]表示从i位置出发到达楼顶，此时的最小花费
class Solution_2 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[n - 1] = cost[n - 1], dp[n - 2] = cost[n - 2];

        for (int i = n - 3; i >= 0; i--)
            dp[i] = min(dp[i + 1] + cost[i], dp[i + 2] + cost[i]);

        return min(dp[0], dp[1]);
    }
};
