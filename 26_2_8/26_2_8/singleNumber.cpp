#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//只出现一次的数字_1
//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
//
//
//示例 1 ：
//
//输入：nums = [2, 2, 1]
//
//输出：1
//
//示例 2 ：
//
//输入：nums = [4, 1, 2, 1, 2]
//
//输出：4
//
//示例 3 ：
//
//输入：nums = [1]
//
//输出：1

//挨个异或，最后相同的数字会异或为0，最后的结果是单出来的数字
class Solution_1 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;

        for (auto x : nums)
        {
            ret ^= x;
        }
        return ret;
    }
};

//只出现一次的数字_2
//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//
//你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
//
//示例 1：
//
//输入：nums = [2, 2, 3, 2]
//输出：3
//
//示例 2：
//
//输入：nums = [0, 1, 0, 1, 0, 1, 99]
//输出：99

//把每个整数元素的每一位都相加,若单出来那个数的那一位是1,则总和%3的结果刚好是1,若那一位是0,则%3=0
class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;

        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (auto x : nums)
            {
                sum += (x >> i) & 1;
            }

            //若%3的结果为1,则将ret的i位改为1
            if (sum % 3)
                ret |= (1 << i);
        }
        return ret;
    }
};

//只出现一次的数字_3
//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//
//你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
//
//示例 1：
//
//输入：nums = [1, 2, 1, 3, 2, 5]
//输出：[3, 5]
//解释：[5, 3] 也是有效的答案。
//
//示例 2：
//
//输入：nums = [-1, 0]
//输出：[-1, 0]
//
//示例 3：
//
//输入：nums = [0, 1]
//输出：[1, 0]

//挨个异或，最后的结果一定是未成对的两个数异或的结果
class Solution_3 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans(2);
        unsigned int sum = 0;

        for (auto x : nums)
            sum ^= x;

        //然后提取出来异或结果的最后一个1，作为分组的依据，因为异或结果中这个1，代表着未成对的两个数的这一位，一个是0，一个是1
        //一定会被分成两组，其他成对的数依旧会被异或成0
        int tmp = sum & -sum;

        for (auto x : nums)
        {
            if ((x & tmp) == 0)
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }
        return ans;
    }
};