#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//排序后，分为元素与下标相等与元素与下标不相等两段，最终找到元素与下标不相等的左端点
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (mid == nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        //查找完当发现下标和元素还是相等，说明缺失的是left+1
        if (nums[left] == left)
            return left + 1;
        else
            return left;
    }
};