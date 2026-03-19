#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//岛屿的最大面积
//给你一个大小为 m x n 的二进制矩阵 grid 。
//
//岛屿 是由一些相邻的 1 (代表土地)构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
//
//岛屿的面积是岛上值为 1 的单元格的数目。
//
//计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
//
//示例 1：
//
//输入：grid = [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0], [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]
//输出：6
//解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
//
//示例 2：
//
//输入：grid = [[0, 0, 0, 0, 0, 0, 0, 0]]
//输出：0


//FloodFill算法-bfs
//在宽搜的过程中，同时记录性质相同的块的个数，在主函数中取最大的即可
class Solution {
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };
    int m, n;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visit[i][j] == false)
                    ret = max(ret, bfs(grid, visit, i, j));
            }
        }
        return ret;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int sr,
        int sc) {
        queue<pair<int, int>> q;
        int count = 0;
        q.push({ sr, sc });
        count++;
        visit[sr][sc] = true;

        while (!q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 &&
                    visit[x][y] == false) {
                    q.push({ x, y });
                    visit[x][y] = true;
                    count++;
                }
            }
        }
        return count;
    }
};