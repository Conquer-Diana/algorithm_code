#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//矩阵中的最长递增路径
//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
//
//对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
//
//示例 1：
//
//输入：matrix = [[9, 9, 4], [6, 6, 8], [2, 1, 1]]
//输出：4
//解释：最长递增路径为[1, 2, 6, 9]。
//
//示例 2：
//
//
//输入：matrix = [[3, 4, 5], [3, 2, 6], [2, 2, 1]]
//输出：4
//解释：最长递增路径是[3, 4, 5, 6]。注意不允许在对角线方向上移动。
//
//示例 3：
//
//输入：matrix = [[1]]
//输出：1

class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    vector<vector<int>> memo;
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        memo.resize(m, vector<int>(n, 0));
        int longest = 0;
        //从每一个位置当成起点开始暴搜，计算最大路径
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                longest = max(longest, dfs(matrix, i, j));
            }

        return longest;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (memo[i][j] != 0)
            return memo[i][j];
        int longest = 1;//最短路径就是1
        //从四个方向dfs，计算最大路径
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y<n && matrix[x][y]>matrix[i][j])
                longest = max(longest, dfs(matrix, x, y) + 1);
        }
        //把当前位置所开始的最大路径记录在备忘录中
        memo[i][j] = longest;
        return longest;
    }
};