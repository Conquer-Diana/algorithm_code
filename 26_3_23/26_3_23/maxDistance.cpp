#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//地图分析
//你现在手里有一份大小为 n x n 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地。
//
//请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回 - 1。
//
//我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和(x1, y1) 这两个单元格之间的距离是 | x0 - x1 | +| y0 - y1 | 。（就是最短距离）
//
//示例 1：
//输入：grid = [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
//输出：2
//解释：
//海洋单元格(1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
//
//示例 2：
//输入：grid = [[1, 0, 0], [0, 0, 0], [0, 0, 0]]
//输出：4
//解释：
//海洋单元格(2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。

//神似《01矩阵》
//从陆地开始去找海洋，即将陆地作为“超级源点”
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)//加入陆地到队列以及dist数组中
                {
                    q.push({ i,j });
                    dist[i][j] = 0;
                }

       // 进行bfs 并记录最大距离
        int ret = -1;
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == -1)
                {
                    q.push({ x,y });
                    dist[x][y] = dist[a][b] + 1;
                    ret = max(ret, dist[x][y]);
                }
            }
        }

        return ret;
    }
};