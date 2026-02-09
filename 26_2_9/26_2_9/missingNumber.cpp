#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//丢失的数字
//给定一个包含[0, n] 中 n 个数的数组 nums ，找出[0, n] 这个范围内没有出现在数组中的那个数。
//
//示例 1：
//
//输入：nums = [3, 0, 1]
//
//输出：2
//
//解释：n = 3，因为有 3 个数字，所以所有的数字都在范围[0, 3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
//
//示例 2：
//
//输入：nums = [0, 1]
//
//输出：2
//
//解释：n = 2，因为有 2 个数字，所以所有的数字都在范围[0, 2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
//
//示例 3：
//
//输入：nums = [9, 6, 4, 2, 3, 5, 7, 0, 1]
//
//输出：8
//
//解释：n = 9，因为有 9 个数字，所以所有的数字都在范围[0, 9] 内。8 是丢失的数字，因为它没有出现在 nums 中。

//将[0,n]所有数字与nums数组里的数字全部异或，最后的结果就是缺失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            ret ^= i ^ nums[i];
        }
        ret ^= n;

        return ret;
    }
};