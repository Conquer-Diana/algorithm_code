#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//黄金矿工
//你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m* n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
//
//为了使收益最大化，矿工需要按以下规则来开采黄金：
//
//每当矿工进入一个单元，就会收集该单元格中的所有黄金。
//矿工每次可以从当前位置向上下左右四个方向走。
//每个单元格只能被开采（进入）一次。
//不得开采（进入）黄金数目为 0 的单元格。
//矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
//
//
//示例 1：
//输入：grid = [[0, 6, 0], [5, 8, 7], [0, 9, 0]]
//输出：24
//解释：
//[[0, 6, 0],
//[5, 8, 7],
//[0, 9, 0]]
//一种收集最多黄金的路线是：9 -> 8 -> 7。
//
//示例 2：
//输入：grid = [[1, 0, 7], [2, 0, 6], [3, 4, 5], [0, 3, 0], [9, 0, 20]]
//输出：28
//解释：
//[[1, 0, 7],
//[2, 0, 6],
//[3, 4, 5],
//[0, 3, 0],
//[9, 0, 20]]
//一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。

//同样是在二维网格中搜索，解法与《单词搜索》一样
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
    bool visit[16][16];
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ret = 0;

        //由于起点不止一个，所以在循环里dfs
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 0)
                {
                    visit[i][j] = true;
                    ret = max(ret, dfs(grid, i, j));//记录价值最大值
                    visit[i][j] = false;
                }

        return ret;
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int maxsum = 0;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            int sum = grid[i][j];
            //剪枝
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0 && !visit[x][y])
            {
                visit[x][y] = true;
                sum += dfs(grid, x, y);
                visit[x][y] = false;
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
