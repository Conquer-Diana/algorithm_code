#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//三步问题
//三步问题。有个小孩正在上楼梯，楼梯有 n 阶台阶，小孩一次可以上 1 阶、2 阶或 3 阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模 1000000007（即1e9+7）。
//
//示例 1：
//
//输入：n = 3
//输出：4
//说明：有四种走法
//
//示例 2：
//
//输入：n = 5
//输出：13
//提示 :
//n 范围在[1, 1000000]之间

//动态规划
class Solution {
    const int MOD = 1e9 + 7;
public:
    int waysToStep(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 4;
        vector<int> dp(n + 1);//由于是从1级台阶开始的，所以需要多开一个空间
        dp[1] = 1, dp[2] = 2, dp[3] = 4;//初始化，1级台阶有一种走法，2级有2种，3级有4种（直接走3步，一步一步走，先2后1，先1后2）

        //接下来的台阶走法即，i-1级台阶的走法+i-2级台阶的走法+i-3级台阶的走法
        //注意：由于相加的值可能会很大，所以两个相加就要模上MOD，三个相加再模一次，结果才对
        for (int i = 4; i <= n; i++)
            dp[i] = ((dp[i - 3] + dp[i - 2]) % MOD + dp[i - 1]) % MOD;

        return dp[n];
    }
};