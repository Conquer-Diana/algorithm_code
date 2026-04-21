#define _CRT_SECURE_NO_WARNINGS
#include <vector>

using namespace std;

//打家劫舍_2
//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
//
//示例 1：
//
//输入：nums = [2, 3, 2]
//输出：3
//解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
//示例 2：
//
//输入：nums = [1, 2, 3, 1]
//输出：4
//解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//偷窃到的最高金额 = 1 + 3 = 4 。
//示例 3：
//
//输入：nums = [1, 2, 3]
//输出：3

//与《打家劫舍_1》不同的是，在相邻屋子不能偷的条件下，加上了一个首尾相邻的屋子也不允许一起偷
//所以可以分类讨论：偷不偷第一间屋子
//偷：只有[2,n-2]的屋子能被偷了+第一间屋子的财宝
//不偷：//还能偷[1,n-1]的屋子
class Solution {
    int n = 0;
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        //这两种分类讨论的情况分别在给定区间执行一次打家劫舍_1的操作，最后取最大值即可
        return max(nums[0] + rob_1(nums, 2, n - 2), rob_1(nums, 1, n - 1));
    }

    int rob_1(vector<int>& nums, int begin, int end)
    {
        if (begin > end)
            return 0;
        int sz = end - begin + 1;
        vector<int> fx(sz), gx(sz);

        fx[0] = nums[begin];

        for (int i = begin + 1; i <= end; i++)
        {
            fx[i - begin] = gx[i - begin - 1] + nums[i];
            gx[i - begin] = max(fx[i - begin - 1], gx[i - begin - 1]);
        }

        return max(fx[sz - 1], gx[sz - 1]);
    }
};