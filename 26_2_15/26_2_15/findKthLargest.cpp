#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <ctime>

using namespace std;

//数组中的第k个最大元素
//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
//
//
//示例 1:
//
//输入: [3, 2, 1, 5, 6, 4] , k = 2
//输出 : 5
//
//示例 2 :
//
//输入 : [3, 2, 3, 1, 2, 4, 5, 5, 6] , k = 4
//输出 : 4

//可以用Top-K解决 但是时间复杂度为O(nlogn)
//这里用快速选择算法，在快排三路划分的基础上加入条件判断，时间复杂度O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));

        return qsort(nums, 0, nums.size() - 1, k);
    }

    int qsort(vector<int>& nums, int l, int r, int k)
    {
        if (l == r)
            return nums[l];

        int random = rand();
        int key = nums[random % (r - l + 1) + l];

        int left = l - 1, right = r + 1, i = l;

        //依旧将数组划分为三块
        while (i < right)
        {
            if (nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if (nums[i] == key)
                i++;
            else
                swap(nums[--right], nums[i]);
        }

        //[l,left] [left+1,right-1] [right,r]
        //由于递增的，所以从后往前讨论，计算后两个区间的元素个数
        int c = r - right + 1;
        int b = right - left - 1;//right-1-(left+1)+1

        //如果最后一个区间大于k，则说明答案在这个区间内，继续递归
        if (c >= k)
            return qsort(nums, right, r, k);
        //若后两个区间加起来大于k，则说明答案在==key的区间内，则直接返回key
        else if (b + c >= k)
            return key;
        //若答案在第一个区间内，则在这个区间递归找第k-b-c大的元素
        else
            return qsort(nums, l, left, k - b - c);
    }
};