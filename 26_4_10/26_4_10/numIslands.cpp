#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//岛屿数量（dfs版）
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    vector<vector<bool>> visit;
    int m, n;
    int ret = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        visit.resize(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1' && visit[i][j] == false)
                {
                    visit[i][j] = true;
                    dfs(grid, i, j);
                    ret++;//递归外统计结果，在dfs内统计结果的话，会重复统计
                }

        return ret;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visit[x][y])
            {
                visit[x][y] = true;
                dfs(grid, x, y);
            }
        }
    }
};