#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//连续数组
//给定一个二进制数组 nums, 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
//
//示例 1：
//
//输入 : nums = [0, 1]
//输出 : 2
//解释 : [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
//
//示例 2：
//
//输入 : nums = [0, 1, 0]
//输出 : 2
//解释 : [0, 1] (或[1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。

//将数组中的0全部替换成-1，即找到和为0的最长子数组，与上一篇和为k的子数组解法相似，哈希表+前缀和

//如果有重复的<sum,i>，就保留之前存过的sum，因为之前存的，前面和为sum的数组还短，意味着后面的和为0目标数组长，保留较长的
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;//哈希表里面存 <前缀和，下标>
        hash[0] = -1;//默认有一个前缀和为0的情况，下标为-1

        int sum = 0, ret = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : nums[i];

            if (hash.count(sum))
                ret = max(ret, i - hash[sum]);//长度计算为 i-j
            else
                hash[sum] = i;
        }
        return ret;
    }
};