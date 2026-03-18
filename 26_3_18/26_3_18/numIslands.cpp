#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//岛屿数量
//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//
//岛屿总是被水包围，并且每座岛屿只能由水平方向和 / 或竖直方向上相邻的陆地连接形成。
//
//此外，你可以假设该网格的四条边均被水包围。
//
//示例 1：
//
//输入：grid = [
//	['1', '1', '1', '1', '0'],
//	['1', '1', '0', '1', '0'],
//	['1', '1', '0', '0', '0'],
//	['0', '0', '0', '0', '0']
//]
//输出：1
//
//示例 2：
//
//输入：grid = [
//	['1', '1', '0', '0', '0'],
//	['1', '1', '0', '0', '0'],
//	['0', '0', '1', '0', '0'],
//	['0', '0', '0', '1', '1']
//]
//输出：3

//FloodFill->bfs
//本题需要遍历整个二维数组，bfs的过程中，为了避免找寻上下左右的'1'时会追溯回查找过的'1'，而陷入死循环的情况
//这里可以将查找过的'1'标记为'0'，也可以不破坏原数组，创建一个与grid同等规模的visit数组，存bool值来标记某个位置的'1'是否已经被查找过了
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ret = 0;

        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && visit[i][j] == false)
                {
                    FloodFill_bfs(grid, visit, i, j);//bfs完成一次，说明就是一块岛屿
                    ret++;
                }
            }
        }
        return ret;
    }

    void FloodFill_bfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int sr, int sc)
    {
        queue<pair<int, int>> q;
        q.push({ sr,sc });
        visit[sr][sc] = true;

        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();
            //visit[a][b]=true; 错误

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && visit[x][y] == false)
                {
                    q.push({ x,y });
                    visit[x][y] = true;//修改visit数组必须在入队这里，而不是在出队那里，因为假设[i][j]是陆地，周围也都是陆地，放在出队那里的话，这里的判断会导致周围的陆地重复把[i][j]插入队列，降低效率
                }
            }
        }
    }
};