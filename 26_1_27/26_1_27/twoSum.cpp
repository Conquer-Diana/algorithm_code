#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
//
//你可以按任意顺序返回答案。
//

//示例 1：
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
// 
//示例 2：
//输入：nums = [3, 2, 4], target = 6
//输出：[1, 2]
// 
//示例 3：
//输入：nums = [3, 3], target = 6
//输出：[0, 1]

//双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<int> ret;
        temp = nums;

        int n = temp.size();

        sort(temp.begin(), temp.end());

        int left = 0;
        int right = n - 1;

        //利用单调性控制双指针淘汰数字
        while (left < right)
        {
            if (temp[left] + temp[right] > target)
                right--;
            else if (temp[left] + temp[right] < target)
                left++;
            else
                break;
        }

        if (left < right)
        {
            for (int k = 0; k < n; k++)
            {
                if (nums[k] == temp[left])
                    ret.push_back(k);
                else if (nums[k] == temp[right])
                    ret.push_back(k);
            }
        }
        return ret;
    }
};