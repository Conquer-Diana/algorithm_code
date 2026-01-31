#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;
//二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;//此处防溢出，和left+(right-left+1)/2等价

            if (nums[mid] > target)
                right = mid - 1;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                return mid;
        }

        return -1;
    }
};