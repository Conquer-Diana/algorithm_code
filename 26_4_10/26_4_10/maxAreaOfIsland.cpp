#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//岛屿的最大面积（dfs版）
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    bool visit[51][51];
    int m, n;
    int count;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && !visit[i][j])
                {
                    count = 0;//每次统计一块新陆地之前，把count清零
                    dfs(grid, i, j);
                    ret = max(ret, count);//同样是在dfs后统计最大值
                }
        return ret;
    }

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        count++;
        visit[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visit[x][y])
                dfs(grid, x, y);
        }
    }
};