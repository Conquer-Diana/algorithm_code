#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//和为k的子数组
//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
//
//子数组是数组中元素的连续非空序列。
//
//示例 1：
//
//输入：nums = [1, 1, 1], k = 2
//输出：2
//
//示例 2：
//
//输入：nums = [1, 2, 3], k = 3
//输出：2

//前缀和+哈希表
//假设[0,i]，要找i之前的某个子数组之和等于k，即转化为在[0,i-1]区间内，有多少个前缀和等于sum-k的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;//存储的是前缀和出现的次数
        hash[0] = 1;//当一个区间的前缀和刚好等于k时，即sum-k=0，也属于一种情况

        int sum = 0, ret = 0;//不用真正的前缀和数组，用sum每次+=表示前缀和，判断之后加入到hash表中

        for (auto x : nums)
        {
            sum += x;
            if (hash.count(sum - k))
                ret += hash[sum - k];
            hash[sum]++;
        }

        return ret;
    }
};