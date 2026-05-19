#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//一和零
//给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
//
//请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
//
//如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
//
//示例 1：
//输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
//输出：4
//解释：最多有 5 个 0 和 3 个 1 的最大子集是{ "10","0001","1","0" } ，因此答案是 4 。
//其他满足题意但较小的子集包括{ "0001","1" } 和{ "10","1","0" } 。{ "111001" } 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
//
//示例 2：
//输入：strs = ["10", "0", "1"], m = 1, n = 1
//输出：2
//解释：最大的子集是{ "0", "1" } ，所以答案是 2 。

//二维费用的背包问题——其实就是比01背包多一个限制条件，dp表多一维而已(#`O′)
class Solution_1 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        //dp[i][j][k]表示：从前i个字符串开始选，其中0的个数不超过j，1的个数不超过k的情况下，子集的最大长度
        vector<vector<vector<int>>> dp(num + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        
        //初始化：多开的j和k，放到填表中初始化，只用初始化多开的i，即i=0的时候，为空数组，在0的个数不超过j，1的个数不超过k的情况下，子集的最大长度都为0

        //状态转移方程：
        //不选i：与01背包一样，dp[i-1][j][k]
        //选i：dp[i-1][j-zero][k-one]+1，即从前i-1个字符串开始选，其中0的个数不超过j-当前字符串中0的个数，1的个数不超过k-当前字符串中1的个数的情况下，子集的最大长度加上1（当前字符串->1个）
        //最后在选i的情况存在的前提下，dp[i][j][k]为两者的最大值

        //填表顺序：由于是三维dp表，要用到dp[i - 1][j][k]和dp[i - 1][j - zero][k - one] + 1)，即前一面的的值，所以只要求i从小到大即可，j和k不用管
        for (int i = 1; i <= num; i++)
        {
            //开始之前，先统计当前字符串0和1的个数
            int zero = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int one = strs[i - 1].size() - zero;
            for (int j = 0; j <= m; j++)
            {
                for (int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zero && k >= one)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zero][k - one] + 1);
                }
            }
        }

        //返回值：根据状态表示，返回从字符串数组中所有字符串中选，其中0的个数不超过m，1的个数不超过n的情况下，子集的最大长度
        return dp[num][m][n];
    }
};


//空间优化版
//滚动数组，参照01背包的空间优化方式（删掉一维，修改填表顺序）
class Solution_2 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= num; i++)
        {
            int zero = count(strs[i - 1].begin(), strs[i - 1].end(), '0');
            int one = strs[i - 1].size() - zero;
            for (int j = m; j >= zero; j--)//空间优化后，必须是从大往小，因为之前是要用到dp[i - 1][j - zero][k - one]上一面的值（旧的值）必须在它更新之前使用它
                for (int k = n; k >= one; k--)//从大往小
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);

        }
        return dp[m][n];
    }
};