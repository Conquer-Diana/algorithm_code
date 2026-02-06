#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

// 除自身以外数组的乘积
//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除了 nums[i] 之外其余各元素的乘积 。
//
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
//
//请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//示例 1:
//
//输入: nums = [1, 2, 3, 4]
//输出 : [24, 12, 8, 6]
//
//示例 2 :
//
//输入 : nums = [-1, 1, 0, -3, 3]
//输出 : [0, 0, 9, 0, 0]

//算出每个元素前缀积和后缀积相乘即可
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n), g(n), ret(n);
        f[0] = g[n - 1] = 1;

        //f[i]表示[0~i-1]所有元素的乘积
        for (int i = 1; i < n; i++)
            f[i] = f[i - 1] * nums[i - 1];

        //g[i]表示[i+1~n-1]所有元素的乘积
        for (int i = n - 2; i >= 0; i--)
            g[i] = g[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++)
            ret[i] = f[i] * g[i];

        return ret;
    }
};