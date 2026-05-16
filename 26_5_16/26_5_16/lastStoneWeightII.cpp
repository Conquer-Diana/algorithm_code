#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//最后一块石头的重量 II
//有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
//
//每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。
//
//示例 1：
//输入：stones = [2, 7, 4, 1, 8, 1]
//输出：1
//解释：
//组合 2 和 4，得到 2，所以数组转化为[2, 7, 1, 8, 1]，
//组合 7 和 8，得到 1，所以数组转化为[2, 1, 1, 1]，
//组合 2 和 1，得到 1，所以数组转化为[1, 1, 1]，
//组合 1 和 1，得到 0，所以数组转化为[1]，这就是最优值。
//
//示例 2：
//输入：stones = [31, 26, 33, 21, 40]
//输出：5


//这道题单纯看代码想着“这不就是01背包问题吗？”对，没错，但这道题难在如何将题目问题往01背包问题靠拢
//用示例来演示的过程中发现，最后的结果其实就是将数组中的数前面加上正负号，然后求和，题目要求这些组合中求和的最小值
//到这里，解题思路就类似于《目标和》了，假设将数组中的数分为加+号的与加-号的，加+号的和为a，加-号的绝对值和为b，假设b>=a，a+b=sum，最后要求的即b-a的最小值
//一个数分为两部分，要想使这两部分的差最小，则这两部分相比其他组合更加接近于sum/2（eg：9=4+5=3+6=2+7=1+8）
//即问题就彻底地转化为了01背包问题：物品：数组中的数，物品体积：stones[i]，物品价值：stones[i]，背包容量：sum/2
class Solution_1 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for (auto x : stones) sum += x;
        //dp[i][j]表示：从前i个数开始选，在总和不超过j的情况下，所有选法中的最大和（最大和，因为要最接近sum/2）
        vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1));
        //初始化：01背包的第一列（不包括（0，0））可以放到填表中，因为j=0时，要满足j >= stones[i - 1]，stones[i - 1]也要等于0，则j - stones[i - 1]==0，也就是j的上方，不会越界）
        //第一行表示空数组，总和不超过j，其最大和都为0

        //状态转移方程：1.不选i，为dp[i-1][j]
        //2.选i，在j >= stones[i - 1]的前提下，为dp[i - 1][j - stones[i - 1]] 加上 stones[i - 1]
        //最后在情况2存在的条件下，两者取最大值
        
        //填表顺序：从上至下
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }

        //返回值：dp[n][sum/2]的值，因为是不超过sum/2，所以对应的是上面的a，所以b=sum-dp[n][sum/2]，b-a=sum-2 * dp[n][sum / 2]
        return sum - 2 * dp[n][sum / 2];
    }
};

//空间优化版（降维，修改填表顺序）
class Solution_2 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for (auto x : stones) sum += x;
        vector<int> dp(sum / 2 + 1);

        for (int i = 1; i <= n; i++)
            for (int j = sum / 2; j >= stones[i - 1]; j--)
                dp[j] = max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);

        return sum - 2 * dp[sum / 2];
    }
};

