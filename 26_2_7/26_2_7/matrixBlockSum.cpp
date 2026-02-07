#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//矩阵区域和
//给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和：
//
//i - k <= r <= i + k,
//j - k <= c <= j + k 且
//(r, c) 在矩阵内。
//
//示例 1：
//
//输入：mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 1
//输出： [[12, 21, 16], [27, 45, 33], [24, 39, 28]]
//
//示例 2：
//
//输入：mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]], k = 2
//输出： [[45, 45, 45], [45, 45, 45], [45, 45, 45]]

//二维前缀和模板运用，不要死记，自行推导
//由于模板中原数组行列都是从1开始的，dp数组与其一一对应，所以这里dp数组需要多开一行和一列，坐标的对应关系也要改变
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + mat[i - 1][j - 1] - dp[i - 1][j - 1];

        //由于answer数组与原数组同规模，对应坐标也需要注意
        vector<vector<int>> answer(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            int x1 = max(0, i - k) + 1;
            int x2 = min(m - 1, i + k) + 1;
            for (int j = 0; j < n; j++)
            {
                int y1 = max(0, j - k) + 1;
                int y2 = min(n - 1, j + k) + 1;

                answer[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        }
        return answer;

    }
};