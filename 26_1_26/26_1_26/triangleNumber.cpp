#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//有效三角形的个数
//给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。
//
//示例 1:
//
//输入: nums = [2, 2, 3, 4]
//输出 : 3
//解释 : 有效的组合是 :
//    2, 3, 4 (使用第一个 2)
//    2, 3, 4 (使用第二个 2)
//    2, 2, 3
//
//示例 2 :
//
//    输入 : nums = [4, 2, 3, 4]
//    输出 : 4

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //先把数组升序排序
        sort(nums.begin(), nums.end());
        int n = nums.size();

        //[2,2,3,4,5,9,10]
        int ret = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            //先把10锁定住，比较前面的二元组
            int max = nums[i];
            int left = 0;
            int right = i - 1;

            while (left < right)
            {
                //利用单调性，如果除了10，2与9的和大于10，则说明2后面的数与9之和都大于10，则三元组个数+right-left，将right左移
                if (nums[left] + nums[right] > max)
                {
                    ret += right - left;
                    right--;
                }
                //若除了10，2与5的和小于10，则2与5前面的数之和都比10小，left++
                else
                {
                    left++;
                }
            }
        }
        return ret;
    }
};