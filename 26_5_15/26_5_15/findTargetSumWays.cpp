#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//目标和
//给定一个正整数数组 nums 和一个整数 target 。
//
//向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
//
//例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
//返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
//
//示例 1：
//输入：nums = [1, 1, 1, 1, 1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//- 1 + 1 + 1 + 1 + 1 = 3
//+ 1 - 1 + 1 + 1 + 1 = 3
//+ 1 + 1 - 1 + 1 + 1 = 3
//+ 1 + 1 + 1 - 1 + 1 = 3
//+ 1 + 1 + 1 + 1 - 1 = 3
//
//示例 2：
//输入：nums = [1], target = 1
//输出：1

//上次遇到这道题还是在递归回溯暴搜的时候，那次超过的人数很少
//这次，将问题转换，用0/1背包来解
//将一整个数组的和sum分成添加+号的数的和a与添加-号的数的和的绝对值b，这样可以得到两个等式：a-b=target，a+b=sum，所以解得a=（target+sum）/2
//所以问题就转换成了：在和为sum的数组中找到一些和为a的数，就自然的联想到了0/1背包的解法
class Solution_1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for (auto num : nums) sum += num;
        int a = (target + sum) / 2;
        //dp之前先优先判断target + sum是否能被2整除，奇数的话不可能分为两部分
        if ((target + sum) % 2 == 1)
            return 0;

        //状态表示：dp[i][j]表示：在前i个数中选，恰好和为j的所有选法个数
        vector<vector<int>> dp(n + 1, vector<int>(a + 1));
        //初始化：（0，0）位置表示：空数组要凑成和为0的选法个数，为1，不选即可
        //第一行表示：空数组要凑成和为j的选法个数，为0，做不到
        //第一列表示：从前i个数选，凑成和为0的选法，注意因为nums[i]是可能为0的，所以这里的选法不能直接判断出来，需要放到填表之中，而且当j==0时，j >= nums[i - 1]这个条件如果成立，说明nums[i-1]也是0，
        // dp[i - 1][j - nums[i - 1]]也表示dp[i][j]上面的那个数，不会越界
        dp[0][0] = 1;

        //状态转移方程：1.不选i：选法为dp[i-1][j]
        //2.选i，在前提为背包容量>=物品体积时，选法为dp[i-1][j-nums[i]]，这里不用加东西，因为都是在dp[i-1][j-nums[i]]这些选法的基础上选了i，并没有新选法的诞生
        //最后dp[i][j]为两种选法（2存在的情况下）的和
        
        //填表顺序：从上至下
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= a; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        //返回值根据状态表示返回从整个数组中选，恰好和为a的选法
        return dp[n][a];
    }
};

//空间优化版
//老样子，用滚动数组，将原有的二维dp表降维，修改填表顺序
class Solution_2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for (auto num : nums) sum += num;
        int a = (target + sum) / 2;
        if ((target + sum) % 2 == 1)
            return 0;

        vector<int> dp(a + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = a; j >= nums[i - 1]; j--)
                dp[j] += dp[j - nums[i - 1]];

        return dp[a];
    }
};