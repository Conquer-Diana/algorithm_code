#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//在排序数组中查找元素的第一个和最后一个位置
//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回[-1, -1]。
//
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//
//
//示例 1：
//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]
//
//示例 2：
//输入：nums = [5, 7, 7, 8, 8, 10], target = 6
//输出：[-1, -1]
//
//示例 3：
//输入：nums = [], target = 0
//输出：[-1, -1]


//二分进阶模板，主要是找出二段性
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if (nums.size() == 0)
            return { -1,-1 };

        vector<int> ret;

        //1.二分左端点
        while (left < right)//统一都用left<right，若用<=，当nums[mid]>=target时，right不动，会死循环
        {
            int mid = left + (right - left) / 2;//与右端点对比理解
            //当只有两个数时，right-left不加1，mid是左边的那个
            //right-left+1，mid是右边的那个
            //由于左端点这个循环内right可能不动，导致死循环，所以左端点这边要用不加1的

            //以<和>=划分两个区间
            if (nums[mid] < target)
                left = mid + 1;//左边不可能有答案，直接放心加1
            else
                right = mid;//右边可能是答案，让其等于
        }
        if (nums[left] == target)
            ret.push_back(left);
        else
            ret.push_back(-1);

        left = 0;
        right = nums.size() - 1;

        //2.二分右端点
        while (left < right)
        {
            //由于右端点这个循环内left可能不动，所以右端点这边要用加1的
            int mid = left + (right - left + 1) / 2;

            //划分为<=和>两个区间
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }
        if (nums[right] == target)
            ret.push_back(right);
        else
            ret.push_back(-1);

        return ret;
    }
};