#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//迷宫中离入口最近的出口
//给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示你一开始所在格子的行和列。
//
//每一步操作，你可以往 上，下，左 或者 右 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。
//
//请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 - 1 。
//
//示例 1：
//
//输入：maze = [["+", "+", ".", "+"], [".", ".", ".", "+"], ["+", "+", "+", "."]], entrance = [1, 2]
//输出：1
//解释：总共有 3 个出口，分别位于(1, 0)，(0, 2) 和(2, 3) 。
//一开始，你在入口格子(1, 2) 处。
//- 你可以往左移动 2 步到达(1, 0) 。
//- 你可以往上移动 1 步到达(0, 2) 。
//从入口处没法到达(2, 3) 。
//所以，最近的出口是(0, 2) ，距离为 1 步。
//
//示例 2：
//
//输入：maze = [["+", "+", "+"], [".", ".", "."], ["+", "+", "+"]], entrance = [1, 0]
//输出：2
//解释：迷宫中只有 1 个出口，在(1, 2) 处。
//(1, 0) 不算出口，因为它是入口格子。
//初始时，你在入口与格子(1, 0) 处。
//- 你可以往右移动 2 步到达(1, 2) 处。
//所以，最近的出口为(1, 2) ，距离为 2 步。
//
//示例 3：
//
//输入：maze = [[".", "+"]], entrance = [0, 0]
//输出： - 1
//解释：这个迷宫中没有出口。
//
//提示：
//
//maze.length == m
//maze[i].length == n
//1 <= m, n <= 100
//maze[i][j] 要么是 '.' ，要么是 '+' 。
//entrance.length == 2
//0 <= entrancerow < m
//0 <= entrancecol < n
//entrance 一定是空格子。

//bfs解决最短路径问题（边权为1（或者边权相同）的最短路径问题）
//解法：从起点开始来一次bfs即可
//把与起点相连的点添加进队列后，并在visit数组中标记，弹出时将这些相连的点依次都弹出，并再次把相连的点加入队列，如果经过重复点，则不加入队列（因为重复了说明之前有点已经经过这里了，而现在重复则肯定不是最短路径）
//第一次遇到终点时，则可以停下了，此时就是最短路径
//最短路径==每弹出一批队列中的数（一层）就++
class Solution {
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };
    bool visit[101][101];
    int m, n;

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        memset(visit, false, sizeof(visit));
        q.push({ entrance[0], entrance[1] });
        visit[entrance[0]][entrance[1]] = true;

        int count = 1;
        while (!q.empty())
        {
            //相比FloodFill多了控制弹出一批队列元素的循环
            int size = q.size();
            while (size--)
            {
                auto [a, b] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == '.' && visit[x][y] == false)
                    {
                        //如果迷宫走到边缘，则为出口
                        if (x == 0 || x == m - 1 || y == 0 || y == n - 1)
                            return count;
                        q.push({ x, y });
                        visit[x][y] = true;
                    }
                }
            }
            count++;
        }

        return -1;
    }
};