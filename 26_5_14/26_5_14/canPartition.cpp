#define _CRT_SECURE_NO_WARNINGS
#include <vector>

using namespace std;

//分割等和子集
//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
//
//示例 1：
//输入：nums = [1, 5, 11, 5]
//输出：true
//解释：数组可以分割成[1, 5, 5] 和[11] 。
//
//示例 2：
//输入：nums = [1, 2, 3, 5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。

//01背包
//转化为：从该数组中找到一些数字和为sum/2，如果有这些数字的话，就会有另一批数字和也等于sum/2
class Solution_1 {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto num : nums)
            sum += num;

        //dp前的判断：如果总和为奇数的话，则无论如何都不能分成两个部分，直接返回false
        if (sum % 2 == 1)
            return false;

        //dp[i][j]表示：从前i个数里面选，所有的选法中，能否凑成sum/2（这里相对于0/1背包问题还容易一些，因为，0/1背包还要求最大价值，这里只用看是否能找出数来凑成sum/2，sum/2相当于背包容量）
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));

        //初始化：多开一行和一列，方便填表
        //第0列表示挑选数凑成和为0，这时候不选即可，为true
        //第0行（不包括（0，0））表示没有数字，但要凑成num/2，这做不到，为false
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        //状态转移方程：
        //1.不选i，为dp[i-1][j]
        //2.选i，为dp[i-1][j-nums[i]]，前提是j>=nums[i]，即当前的背包容量要大于等于当前物品的体积，然后去寻找是否能从前i-1个数中，恰好凑成j-nums[i]
        //最后两种情况满足一种即可

        //填表顺序：从上往下，左右皆可
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= sum / 2; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }

        //返回值：根据状态表示，返回从整个数组的数据个数里面选，所有的选法中，是否能凑成sum/2
        return dp[n][sum / 2];
    }
};

//空间优化版（将dp表降维，用滚动数组改变填表顺序优化）
class Solution_2 {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto num : nums)
            sum += num;

        if (sum % 2 == 1)
            return false;

        //dp表不用再存行了
        vector<bool> dp(sum / 2 + 1, false);
        //根据原来的版本将代码降维
        dp[0] = true;

        for (int i = 1; i <= n; i++)
            //主要优化在这里了，之前是从1到sum/2，现在改变填表顺序（从右往左->防止填下一行时，需要的数据被覆盖）后，将原来的if (j >= nums[i - 1])直接放到循环条件中，意味着当j<nums[i-1]后，后面的值就没有意义了
            for (int j = sum / 2; j >= nums[i - 1]; j--)
                dp[j] = dp[j] || dp[j - nums[i - 1]];

        return dp[sum / 2];
    }
};
