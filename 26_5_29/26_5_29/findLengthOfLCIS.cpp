#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//最长连续递增序列
//给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。——也就是找子数组
//
//连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
//
//示例 1：
//输入：nums = [1,3,5,4,7]
//输出：3
//解释：最长连续递增序列是 [1,3,5], 长度为3。
//尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
//
//示例 2：
//输入：nums = [2,2,2,2,2]
//输出：1
//解释：最长连续递增序列是 [2], 长度为1。

//这道题在用双指针暴力枚举的过程中发现，当j发现一个位置之后不能维持递增的性质时，直接让i瞬移到j的位置继续往下走（因为那个不能维持递增的位置之前的值再让i去遍历的话也没有意义，还是会在这个位置断开），然后过程中统计最大值即可
//贪心+双指针
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;

        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n - 1 && nums[j] < nums[j + 1])
                j++;
            ret = max(ret, j - i + 1);
            i = j + 1;//这一步体现了贪心
        }
        return ret;
    }
};