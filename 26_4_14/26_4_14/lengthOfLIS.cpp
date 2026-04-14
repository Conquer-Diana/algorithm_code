#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//
//子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。
//
//示例 1：
//
//输入：nums = [10, 9, 2, 5, 3, 7, 101, 18]
//输出：4
//解释：最长递增子序列是[2, 3, 7, 101]，因此长度为 4 。
//
//示例 2：
//
//输入：nums = [0, 1, 0, 3, 2, 3]
//输出：4
//
//示例 3：
//
//输入：nums = [7, 7, 7, 7, 7, 7, 7]
//输出：1

//解法一：记忆化搜索
class Solution {
    vector<int> memo;
    int n = 0;
public:
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memo.resize(n);

        int ret = 0;
        for (int i = 0; i < n; i++)
            ret = max(ret, dfs(nums, i));
        return ret;
    }

    int dfs(vector<int>& nums, int pos)
    {
        if (memo[pos] != 0)
            return memo[pos];

        int ret = 1;
        for (int i = pos + 1; i < n; i++)
        {
            if (nums[i] > nums[pos])
            {
                ret = max(ret, 1 + dfs(nums, i));
            }
        }
        memo[pos] = ret;
        return ret;
    }
};

//解法二：记忆化搜索改动态规划
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        //由于记忆化搜索时，得到一个位置的最长递增子序列长度是需要依靠他的下一个位置的值得到，所以动规这里从右向左填表
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                if (nums[j] > nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);

        int ret = 0;
        for (int i = 0; i < n; i++)
            ret = max(ret, dp[i]);

        return ret;
    }
};