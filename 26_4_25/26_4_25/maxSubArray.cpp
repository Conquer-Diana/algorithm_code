#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//最大子数组和
//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//子数组是数组中的一个连续部分。
//
//示例 1：
//输入：nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
//输出：6
//解释：连续子数组[4, -1, 2, 1] 的和最大，为 6 。
//
//示例 2：
//输入：nums = [1]
//输出：1
//
//示例 3：
//输入：nums = [5, 4, -1, 7, 8]
//输出：23

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        //dp[i]表示以i为结尾，所有子数组的最大和
        vector<int> dp(n + 1);//多开一个虚拟节点，简化初始化，虚拟节点初始化为0

        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            //dp[i]这个位置的子数组情况包括：只有自己一个元素，以及以i-1为结尾的子数组+i位置，即以i-1位置为结尾的子数组最大和（dp[i-1]）+nums[i]，两者取最大值
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            //最后从dp表中选最大值为答案
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};