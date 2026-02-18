#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//翻转对
//给定一个数组 nums ，如果 i < j 且 nums[i] > 2 * nums[j] 我们就将(i, j) 称作一个重要翻转对。
//
//你需要返回给定数组中的重要翻转对的数量。
//
//示例 1:
//
//输入: [1, 3, 2, 3, 1]
//输出 : 2
//
//示例 2 :
//
//输入 : [2, 4, 3, 5, 1]
//输出 : 3

//与逆序对差不多，差别在这个是二倍，不能贴合归并排序中合并两个有序数组的比较方式，所以需要在这之前使用双指针先计算出翻转对的个数
//再进行排序工作
class Solution {
    int tmp[50010];
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int ret = 0;

        ret += mergeSort(nums, left, mid);
        ret += mergeSort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;

        while (cur1 <= mid && cur2 <= right)
        {
            while (cur2 <= right && nums[cur1] / 2.0 <= nums[cur2])//乘法会溢出，改为除法
                cur2++;
            ret += right - cur2 + 1;
            cur1++;
        }

        cur1 = left, cur2 = mid + 1;
        while (cur1 <= mid && cur2 <= right)
        {
            if (nums[cur1] <= nums[cur2])
                tmp[i++] = nums[cur2++];
            else
                tmp[i++] = nums[cur1++];
        }
        while (cur1 <= mid)
            tmp[i++] = nums[cur1++];
        while (cur2 <= right)
            tmp[i++] = nums[cur2++];

        for (int i = left; i <= right; i++)
            nums[i] = tmp[i - left];

        return ret;
    }
};