#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//珠宝的最高价值
//现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为：
//
//只能从架子的左上角开始拿珠宝
//每次可以移动到右侧或下侧的相邻位置
//到达珠宝架子的右下角时，停止拿取
//注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]] 。
//
//示例 1：
//
//输入：frame = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
//输出：12
//解释：路径 1→3→5→2→1 可以拿到最高价值的珠宝


class Solution {
    int m, n;
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        m = frame.size(), n = frame[0].size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];//该位置的dp等于上面的位置的dp与左边位置的dp之间的最大值再加上该位置的珠宝价值

        return dp[m][n];
    }
};