#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//乘积最大子数组
//给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
//测试用例的答案是一个 32 - 位 整数。
//
//请注意，一个只包含一个元素的数组的乘积是这个元素的值。
//
//示例 1:
//输入: nums = [2, 3, -2, 4]
//输出 : 6
//解释 : 子数组[2, 3] 有最大乘积 6。
//
//示例 2 :
//输入 : nums = [-2, 0, -1]
//输出 : 0
//解释 : 结果不能为 2, 因为[-2, -1] 不是子数组。

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        //一个dp解决不了问题
        //maxx[i]表示以i为结尾，所有子数组乘积最大的值
        //minx[i]表示以i为结尾，所有子数组乘积最小的值
        vector<int> maxx(n + 1), minx(n + 1);

        maxx[0] = minx[0] = 1;

        int ret = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            //要么是i位置本身，要么是nums[i]为正数，乘以以i-1为结尾的所有子数组的最大值（即maxx[i-1]），要么nums[i]为负数，乘以minx[i-1]
            maxx[i] = max(max(nums[i - 1], nums[i - 1] * maxx[i - 1]), nums[i - 1] * minx[i - 1]);

            //要么是i位置本身，要么是nums[i]为正数，乘以以i-1为结尾的所有子数组的最小值（即minx[i-1]），要么nums[i]为负数，乘以maxx[i-1]
            minx[i] = min(min(nums[i - 1], nums[i - 1] * maxx[i - 1]), nums[i - 1] * minx[i - 1]);
            //从maxx[i]中找最大值
            ret = max(ret, maxx[i]);
        }

        return ret;
    }
};