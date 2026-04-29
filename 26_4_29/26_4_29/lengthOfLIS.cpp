#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。
//
//示例 1：
//输入：nums = [10, 9, 2, 5, 3, 7, 101, 18]
//输出：4
//解释：最长递增子序列是[2, 3, 7, 101]，因此长度为 4 。
//
//示例 2：
//输入：nums = [0, 1, 0, 3, 2, 3]
//输出：4
//
//示例 3：
//输入：nums = [7, 7, 7, 7, 7, 7, 7]
//输出：1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示以i位置为结尾，所有递增子序列中最长的长度
        vector<int> dp(n, 1);

        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            //子序列与子数组不同，所以从i-1开始往前找（i-1，i-2 ......0)，这些值为j，把nums[i]插入每一个位置后面作为子序列，如果此时是递增的，则长度为dp[j]+1,要找最长的递增子序列，就取出每个j对应的dp[j]+1的最大值
            //由于dp初始化为1了，所以就相当于天然的处理了只有该数字自己构成一个子序列的情况，长度为1
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            //最后答案为dp表中的最大值
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};