#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//搜索插入位置
//给定一个排序的整数数组 nums 和一个整数目标值 target ，请在数组中找到 target ，并返回其下标。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//请必须使用时间复杂度为 O(log n) 的算法。
//
//示例 1：
//输入 : nums = [1, 3, 5, 6], target = 5
//输出 : 2
//
//示例 2：
//输入 : nums = [1, 3, 5, 6], target = 2
//输出 : 1
//
//示例 3：
//输入 : nums = [1, 3, 5, 6], target = 7
//输出 : 4

//发现插入时都是先第一次找到比target大的数，所以划分区间为>=和<，转化为查找左区间端点
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if (nums[left] < target)
            return left + 1;

        return left;
    }
};