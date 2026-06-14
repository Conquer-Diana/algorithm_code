#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//可被三整除的最大和
//给你一个整数数组 nums，请你找出并返回能被三整除的元素 最大和。
//
//示例 1：
//输入：nums = [3, 6, 5, 1, 8]
//输出：18
//解释：选出数字 3, 6, 1 和 8，它们的和是 18（可被 3 整除的最大和）。
//
//示例 2：
//输入：nums = [4]
//输出：0
//解释：4 不能被 3 整除，所以无法选出数字，返回 0。
//
//示例 3：
//输入：nums = [1, 2, 3, 4, 4]
//输出：12
//解释：选出数字 1, 3, 4 以及 4，它们的和是 12（可被 3 整除的最大和）。
//
//
//提示：
//1 <= nums.length <= 4 * 104
//1 <= nums[i] <= 104

//解法一：正难则反+贪心+分类讨论
//正难则反就是不从每一个数加起来是否能整除3这条路走，而是从这个数组的总和%3的结果去分类讨论，减去数这条路来走
//1.sum%3==0时，总和就是sum，直接返回
//2.sum%3==1时，可以拆成一个x（x%3==1）和（sum-x）%3==0（或者拆成x1,x2,x3,x4，%3都等于1，（sum-x1-x2-x3-x4）%3==0，等等，但都可以归为一种，因为有三个数%3==1，这三个数的和就能被3整除整合到sum中）
// 或者拆成两个y1，y2(y1,y2%3==2)和（sum-y1-y2)%3==0，由于是要求能被3整除的最大和，所以（sum-x）x是所有%3等于1的数的最小值，(sum-y1-y2),y1和y2是所有%3==2的最小值和次小值
//3.sum%3==2时，与上面一样，可拆成可以拆成一个y（y%3==2）和（sum-y）%3==0 或者 拆成两个x1，x2(x1,x2%3==1)和（sum-x1-x2)%3==0
//由于是要求能被3整除的最大和，所以（sum-y）y是所有%3等于2的数的最小值，(sum-x1-x2),x1和x2是所有%3==1的最小值和次小值

//最小值和次小值的求法
//分类讨论，刚开始先将最小值x1次小值x2设置为无穷大
//判断一个值，在x1前面还是在[x1,x2]之间还是在x2后面，更新最小和次小即可
class Solution_1 {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0, x1, x2, y1, y2;
        x1 = x2 = y1 = y2 = 0x3f3f3f3f;
        for (auto num : nums)
        {
            sum += num;
            if (num % 3 == 1)
            {
                if (num < x1)
                {
                    x2 = x1;
                    x1 = num;
                }
                else if (num >= x1 && num <= x2)
                    x2 = num;
            }
            if (num % 3 == 2)
            {
                if (num < y1)
                {
                    y2 = y1;
                    y1 = num;
                }
                else if (num >= y1 && num <= y2)
                    y2 = num;
            }
        }
        if (sum % 3 == 1)
            return max(sum - x1, sum - y1 - y2);
        else if (sum % 3 == 2)
            return max(sum - y1, sum - x1 - x2);

        return sum;
    }
};

//解法二：动态规划（通用解法，当题目修改一下，变成整除4，5等数时，贪心分类讨论就太复杂了）
//dp[i][j]表示：以i位置为结尾，总和%3==j的最大和
class Solution_2 {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(3));
        //初始化：多开一行，表示没有选择任何数，此时总和为0，%3也等于0，所以dp[0][1] 和 dp[0][2]属于非法状态，由于下面要取最大值，所以初始化为无穷小
        dp[0][0] = 0, dp[0][1] = dp[0][2] = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                //这里的状态转移方程是用数学简化了的，每个if对于每个余数j都有不同的推导方式，比如，当nums[i - 1] % 3 == 1时，dp[i][0]可以不选当前数，就是dp[i-1][0]，也可以选择当前数，就是dp[i-1][2],其他是同样道理
                if (nums[i - 1] % 3 == 0)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + nums[i - 1]) % 3] + nums[i - 1]);
                else if (nums[i - 1] % 3 == 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + nums[i - 1] + 1) % 3] + nums[i - 1]);
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + nums[i - 1] + 2) % 3] + nums[i - 1]);
            }
        }
        return dp[n][0];
    }
};