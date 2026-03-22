#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//飞地的数量
//给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。
//
//一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。
//
//返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。
//
//示例 1：
//
//输入：grid = [[0, 0, 0, 0], [1, 0, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]]
//输出：3
//解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
//
//示例 2：
//
//输入：grid = [[0, 1, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 0]]
//输出：0
//解释：所有 1 都在边界上或可以到达边界。


//从里面向外找边界很难找，找的话也需要两遍bfs或dfs（一遍查看是否走得通，一遍修改标记位）
//所以正难则反，将边界的1当作起点，向内部寻找1，修改标记位
//最后遍历二维数组中，内部那些值为1，但未被标记的就是结果
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    bool visit[501][501];
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        memset(visit, false, sizeof(visit));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
            {
                q.push({ i,0 });
                visit[i][0] = true;
            }
            if (grid[i][n - 1] == 1)
            {
                q.push({ i,n - 1 });
                visit[i][n - 1] = true;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 1)
            {
                q.push({ 0,j });
                visit[0][j] = true;
            }
            if (grid[m - 1][j] == 1)
            {
                q.push({ m - 1,j });
                visit[m - 1][j] = true;
            }
        }

        //这里由于只用修改标记位，所以不用step和q.size()这样一层一层的遍历，不用管当时是属于哪一层的
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visit[x][y])
                {
                    q.push({ x,y });
                    visit[x][y] = true;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && !visit[i][j])
                    ret++;

        return ret;


    }
};