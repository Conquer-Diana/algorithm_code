#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//跳跃游戏 II
//给定一个长度为 n 的 0 索引整数数组 nums。初始位置在下标 0。
//每个元素 nums[i] 表示从索引 i 向后跳转的最大长度。换句话说，如果你在索引 i 处，你可以跳转到任意 (i + j) 处：
//
//0 <= j <= nums[i] 且
//i + j < n
//返回到达 n - 1 的最小跳跃次数。测试用例保证可以到达 n - 1。
//
//示例 1:
//输入: nums = [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
//
//示例 2:
//输入: nums = [2,3,0,1,4]
//输出: 2

//解法一：动态规划
//dp[i]表示到达当前位置的最小跳跃次数——线性dp,时间复杂度为O(n^2)
class Solution_1 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (nums[j] + j >= i)
                    dp[i] = min(dp[i], dp[j] + 1);

        return dp[n - 1];
    }
};

//解法二：贪心,模拟层序遍历的过程
//比如:[2,3,1,1,4,2,6,7,1,5,8],从起点开始，能到的下一区间是[3,1](下标[1,2]),能到的下一区间是[1,4](下标[3,4]),能到的下一区间为[2,6,7,1](下标[5,6,7,8]),能到的下一区间为[5,8],已经覆盖了i=n-1，统计走了多少步即可
//像层序遍历这样一层层往下推理，并统计步数即可
//用left和right双指针来标记每一层的左端点与右端点，更新时，去找当前层里nums[i]+i的最大值（贪心），作为下一层的right，下一层的left则为上一层的right+1即可（中间一定没有断开，因为上一层既然能到新一层的right了，那么一定可以到
//比该right小的新的left），由于用例一定能到达n-1，所以当发现right>=n-1时，则直接返回统计步数即可
class Solution_2 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int ret = 0;

        while (right < n - 1)
        {
            int tmp = 0;
            while (left <= right)
                tmp = max(tmp, left + nums[left++]);//在找最大值的过程中，left会自动到新的位置
            right = tmp;
            ret++;
        }
        return ret;
    }
};
