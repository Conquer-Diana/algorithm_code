#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//等差数列划分
//如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
//
//例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和[3, -1, -5, -9] 都是等差数列。
//给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
//
//子数组 是数组中的一个连续序列。
//
//示例 1：
//
//输入：nums = [1, 2, 3, 4]
//输出：3
//解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和[1, 2, 3, 4] 自身。
//
//示例 2：
//
//输入：nums = [1]
//输出：0

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dp(n);
        //dp[i]表示以i位置为结尾，所有子数组为等差数列的个数
        dp[0] = dp[1] = 0;//由于题目说至少要有三个元素，所以前两个直接初始化为0

        int ret = 0;
        for (int i = 2; i < n; i++)
        {
            //dp[i]看前两个位置，如果公差相等，说明以i-1位置为结尾的所有等差数列子数组，末尾填上nums[i]一样等差数列子数组，即dp[i-1]，注意，因为num[i-2],nums[i-1],nums[i]这三个数也可以单独成为一个等差数列，所以需多加一个1
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                dp[i] = dp[i - 1] + 1;
            //如果公差不相等，则前面就算是等差数列，填上nums[i]也不是了，所以dp[i]为0
            else
                dp[i] = 0;

            ret += dp[i];//最后结果为以每一个位置为结尾所能构成的等差数列个数之和
        }

        return ret;
    }
};