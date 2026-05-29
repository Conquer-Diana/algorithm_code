#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//递增的三元子序列
//给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。
//
//如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
//
//示例 1：
//
//输入：nums = [1,2,3,4,5]
//输出：true
//解释：任何 i < j < k 的三元组都满足题意
//
//示例 2：
//输入：nums = [5,4,3,2,1]
//输出：false
//解释：不存在满足题意的三元组
//
//示例 3：
//输入：nums = [2,1,5,0,4,6]
//输出：true
//解释：其中一个满足题意的三元组是 (1, 4, 5)，因为 nums[1] == 1 < nums[4] == 4 < nums[5] == 6

//这道题其实就是《最长递增子序列》的贪心+二分解法的削弱版，甚至不用二分
//因为是只用找三个数的子序列，所以放到前一题的数组来看的话，就是数组长度一旦达到三就可以返回true了
//然后可以只用两个变量就可以完成
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        //a代表长度为1的最后一个元素的最小值，b代表长度为2的最后一个元素的最小值
        //a赋值为第一个元素，b赋值为无穷大
        int a = nums[0], b = INT_MAX;

        for (int i = 1; i < n; i++)
        {
            //如果一个数大于b，则说明可以接在b的后面构成长度为3的，那么直接返回true
            if (nums[i] > b)
                return true;
            //如果a<x<=b，将x把原来b的值给覆盖掉
            if (nums[i] > a)
                b = nums[i];
            //如果x<=a，将x覆盖掉a的值
            else
                a = nums[i];
        }

        return false;
    }
};