#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//地图中的最高点
//给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。
//
//如果 isWater[i][j] == 0 ，格子(i, j) 是一个 陆地 格子。
//如果 isWater[i][j] == 1 ，格子(i, j) 是一个 水域 格子。
//你需要按照如下规则给每个单元格安排高度：
//
//每个格子的高度都必须是非负的。
//如果一个格子是 水域 ，那么它的高度必须为 0 。
//任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
//找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。
//
//请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子(i, j) 的高度。如果有多种解法，请返回 任意一个 。
//
//示例 1：
//输入：isWater = [[0, 1], [0, 0]]
//输出： [[1, 0], [2, 1]]
//解释：上图展示了给各个格子安排的高度。
//蓝色格子是水域格，绿色格子是陆地格。
//
//示例 2：
//输入：isWater = [[0, 0, 1], [1, 0, 0], [0, 0, 0]]
//输出： [[1, 1, 0], [0, 1, 1], [1, 2, 2]]
//解释：所有安排方案中，最高可行高度为 2 。
//任意安排方案中，只要最高高度为 2 且符合上述规则的，都为可行方案。

//与《01矩阵》换汤不换药
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (isWater[i][j] == 1)//将所有水域先加入队列中，以及加入dist数组中并修改为0，作为“超级源点”
                {
                    dist[i][j] = 0;
                    q.push({ i,j });
                }

        //进行bfs填充dist数组
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] == -1)
                {
                    q.push({ x,y });
                    dist[x][y] = dist[a][b] + 1;
                }
            }
        }
        return dist;
    }
};