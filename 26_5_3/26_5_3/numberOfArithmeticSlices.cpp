#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <unordered_map>

using namespace std;

//等差数列划分 II - 子序列
//给你一个整数数组 nums ，返回 nums 中所有 等差子序列 的数目。
//
//如果一个序列中 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该序列为等差序列。
//
//例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和[3, -1, -5, -9] 都是等差序列。
//再例如，[1, 1, 2, 5, 7] 不是等差序列。
//数组中的子序列是从数组中删除一些元素（也可能不删除）得到的一个序列。
//
//例如，[2, 5, 10] 是[1, 2, 1, 2, 4, 1, 5, 10] 的一个子序列。
//题目数据保证答案是一个 32 - bit 整数。
//
//示例 1：
//输入：nums = [2, 4, 6, 8, 10]
//输出：7
//解释：所有的等差子序列为：
//[2, 4, 6]
//[4, 6, 8]
//[6, 8, 10]
//[2, 4, 6, 8]
//[4, 6, 8, 10]
//[2, 4, 6, 8, 10]
//[2, 6, 10]
//
//示例 2：
//输入：nums = [7, 7, 7, 7, 7]
//输出：16
//解释：数组中的任意子序列都是等差子序列。

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        //dp[i][j]表示：以i和j为最后两个位置，所有等差子序列的数目
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<long long, vector<int>> hash;

        //优化：把所有值与其下标存入下标数组中
        for (int i = 0; i < n; i++)
            hash[nums[i]].push_back(i);

        int ret = 0;
        for (int i = 1; i < n; i++)//固定i
        {
            for (int j = i + 1; j < n; j++)//枚举j
            {
                long long tmp = (long long)nums[i] * 2 - nums[j];//防止数字越界
                if (hash.count(tmp))
                    //遍历下标数组（因为要统计个数，而不是最长的长度，所以所有重复的数字都要统计
                    for (auto k : hash[tmp])
                        //这里还要判断一下，k要在i前面
                        if (k < i)
                            dp[i][j] += dp[k][i] + 1;

                ret += dp[i][j];//最后结果为dp表所有值的和
            }
        }
        return ret;
    }
};