#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

// 最大连续1的个数 III
//给定一个二进制数组 nums 和一个整数 k，假设最多可以翻转 k 个 0 ，则返回执行操作后 数组中连续 1 的最大个数 。
//
//示例 1：
//
//输入：nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], K = 2
//输出：6
//解释：[1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1]
//粗体数字从 0 翻转到 1，最长的子数组长度为 6。
//
//示例 2：
//
//输入：nums = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1], K = 3
//输出：10
//解释：[0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1]
//粗体数字从 0 翻转到 1，最长的子数组长度为 10。

//滑动窗口，转化为找出最长的子数组，0的长度不超过k个
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int zero = 0;
        int ret = 0;

        while (right < nums.size())
        {
            if (nums[right] == 0)//0计数，1忽略
                zero++;

            while (zero > k)
            {
                if (nums[left++] == 0)//左边出窗口
                    zero--;
            }

            ret = max(ret, right - left + 1);

            right++;
        }

        return ret;
    }
};