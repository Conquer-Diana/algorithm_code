#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//长度最小的子数组
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组[numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

//示例 1：
//
//输入：target = 7, nums = [2, 3, 1, 2, 4, 3]
//输出：2
//解释：子数组[4, 3] 是该条件下的长度最小的子数组。
//示例 2：
//
//输入：target = 4, nums = [1, 4, 4]
//输出：1
//示例 3：
//
//输入：target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]
//输出：0

//滑动窗口（同向双指针）当用暴力法模拟时发现两个指针都不会回退，则可以考虑滑动窗口
// 1.left=0,right=0
// 2.进窗口
// 3.判断
// 4.出窗口
// 5.更新结果（这一步依题而定，可能在进窗口后，可能在出窗口前）
//利用单调性，都是正整数的话，如果加到一个地方已经大于等于target,则后面的就不用加了
//则先记录再出窗口，继续循环判断
//即外层循环是右指针，内层循环是左指针
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = INT_MAX;

        while (right < nums.size())
        {
            sum += nums[right];

            while (sum >= target)
            {
                len = min(len, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return len == INT_MAX ? 0 : len;
    }
};