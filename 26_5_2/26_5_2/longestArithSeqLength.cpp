#define _CRT_SECURE_NO_WARNINGS


#include <vector>
#include <unordered_map>

using namespace std;

//最长等差数列
//给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。
//
//回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i + 1] - seq[i](0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的。
//
//	示例 1：
//	输入：nums = [3, 6, 9, 12]
//	输出：4
//	解释：
//	整个数组是公差为 3 的等差数列。
//
//	示例 2：
//	输入：nums = [9, 4, 7, 2, 10]
//	输出：3
//	解释：
//	最长的等差子序列是[4, 7, 10]。
//
//	示例 3：
//	输入：nums = [20, 1, 15, 3, 10, 5, 8]
//	输出：4
//	解释：
//	最长的等差子序列是[20, 15, 10, 5]。


//这道题的思路与《最长的斐波那契的子序列的长度》很像，要用两个位置作为结尾往前推导才对（只以一个作为结尾，不知道等差数列是什么样子）
//但这道题的细节需要优化的点比那道题多，非常不好想到
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        //优化：
        unordered_map<int, int> hash;
        hash[nums[0]] = 0;

        vector<vector<int>> dp(n, vector<int>(n, 2));//dp表与初始化（初始化为最差情况2）

        int ret = 2;
        //这道题如果不优化，由于需要固定i，j两个位置，时间复杂度就已经是O(n^2)了，但还需要根据差值去寻找i前面的k（k<i<j），相当于又遍历一遍，时间复杂度达到了O(n^3)，会超时
        //所以考虑到，本题只用考虑距离i位置最近的那个k即可（前面的k与最近的k中间还可能有更优的情况，所以最近的肯定长度最长），就想到可以一边dp，一边将最近的k的值与下标存入hash表中
        //但此时填表顺序就要有考量了，1.先固定j，再枚举i，2.先固定i，再枚举j
        //第1种方式的话，固定j后，i从后或者从前开始枚举，由于i是一直在移动的，要找的也是距离i最近的，所以这个值也是一直在变，外层循环j++后，由于k<i，hash 里面必须只有比 i 小的下标，所以每次外循环都要请客hash表，消耗极大
        //所以采取第2种方式 ，当我们在内层循环枚举j时，i是固定不动的。此时 hash 表中存的恰好就是i左边所有的数。

        for (int i = 1; i < n; i++)//固定i，从1开始（从0开始的话没必要，因为初始化把长度都设为2了）
        {
            for (int j = i + 1; j < n; j++)//枚举j，从i+1位置开始
            {
                // 在这里查找 k，此时 hash 里的下标都是在 i 之前的
                int tmp = 2 * nums[i] - nums[j];
                if (hash.count(tmp))
                    dp[i][j] = dp[hash[tmp]][i] + 1;

                ret = max(ret, dp[i][j]);
            }
            //这一轮的所有 j 处理完后，才把 i 存入 hash，所以就算有重复的数，也能保证下一轮拿到的坐标是最新的（最近的）
            hash[nums[i]] = i;
        }

        return ret;//返回值是dp表中的最大值
    }
};