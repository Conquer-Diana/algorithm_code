#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//组合总和 Ⅳ
//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//
//题目数据保证答案符合 32 位整数范围。
//
//示例 1：
//输入：nums = [1, 2, 3], target = 4
//输出：7
//解释：
//所有可能的组合为：
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//请注意，顺序不同的序列被视作不同的组合。
//
//示例 2：
//输入：nums = [9], target = 3
//输出：0

// 这道题看似是01背包问题，但实际上仔细分析下来不是
// 题目虽说是“组合总和”，但根据示例来看，同时出现了(1, 1, 2)，(2, 1, 1)，说明是排列问题，但01背包问题是解决“有限制条件”的组合问题的
// 因为01背包状态表示：从前i个物品中选，总体积不超过j的情况下的最大价值，这个里面是没有规定第一个位置选什么，最后一个位置选什么之类的，也就是没有规定顺序，是组合
// 所以这道题用01背包是陷阱
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        //根据分析问题的过程，发现重复子问题，抽象出一个状态表示
        //dp[i]表示：能凑成总和为i，所有的排列数
        vector<unsigned int> dp(target + 1);

        //初始化：当要凑成总和为0的时候，排列为空集，排列数为1
        dp[0] = 1;

        //状态转移方程：
        //当当前的i>=nums[j]时，dp[i]等于所有dp[i-nums[j]]的总和

        //填表顺序：从左往右
        for (int i = 1; i <= target; i++)
            for (int j = 0; j < n; j++)
                if (i >= nums[j])
                    dp[i] += dp[i - nums[j]];

        //返回能凑成总和为target的所有排列数
        return dp[target];
    }
};