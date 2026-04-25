#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//环形子数组的最大和
//给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
//
//环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。
//
//子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
//
//示例 1：
//输入：nums = [1, -2, 3, -2]
//输出：3
//解释：从子数组[3] 得到最大和 3
//
//示例 2：
//输入：nums = [5, -3, 5]
//输出：10
//解释：从子数组[5, 5] 得到最大和 5 + 5 = 10
//
//示例 3：
//输入：nums = [3, -2, 2, -3]
//输出：3
//解释：从子数组[3] 和[3, -2, 2] 都可以得到最大和 3

//“环形”这个概念也可以分为两种情况：1.答案子数组在整个数组中间，这时候就是《最大子数组和》的解法
//2.答案分布在数组末尾加上数组开头的部分，因为整个数组和为定值，开头和结尾的和为最大，那么被这两个部分夹在中间的连续部分的和就是最小的
//所以可以同时填写两个dp表，最大子数组和以及最小子数组和，最后取最大子数组和与（sum-最小子数组和）两者的最大值即可
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxx(n + 1), minx(n + 1);

        int fmax = INT_MIN, gmin = INT_MAX, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            maxx[i] = max(nums[i - 1], maxx[i - 1] + nums[i - 1]);
            fmax = max(fmax, maxx[i]);
            minx[i] = min(nums[i - 1], minx[i - 1] + nums[i - 1]);
            gmin = min(gmin, minx[i]);
            sum += nums[i - 1];
        }

        return sum == gmin ? fmax : max(fmax, sum - gmin);//小细节：当数组全为负数时，fmax是那个最大的负数，但gmin要最小，即为整个数组的和，即gmin==sum，此时sum-gmin=0，但此时结果应该为最大的那个负数，即fmax
    }
};