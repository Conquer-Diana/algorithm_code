#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//太平洋大西洋水流问题
//有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
//
//这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标(r, c) 上单元格 高于海平面的高度 。
//
//岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
//
//返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格(ri, ci) 流动 既可流向太平洋也可流向大西洋 。
//
//示例 1：
//
//输入: heights = [[1, 2, 2, 3, 5], [3, 2, 3, 4, 4], [2, 4, 5, 3, 1], [6, 7, 1, 4, 5], [5, 1, 1, 2, 4]]
//输出 : [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
//
//示例 2：
//
//输入 : heights = [[2, 1], [1, 2]]
//输出 : [[0, 0], [0, 1], [1, 0], [1, 1]]


//这道题“正难则反”，从网格内某一个方块去判断是否能流向太平洋或者大西洋太困难了
//反过来，从太平洋或者大西洋反过来看能渗透哪些方块，最终存在于两个海洋visit数组中的坐标，即为答案
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    bool Pacvisit[201][201];
    bool Atvisit[201][201];
    int m, n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();

        //处理太平洋
        for (int i = 0; i < m; i++)
            dfs(heights, i, 0, 0);
        for (int j = 1; j < n; j++)
            dfs(heights, 0, j, 0);

        //处理大西洋
        for (int i = 0; i < m; i++)
            dfs(heights, i, n - 1, 1);
        for (int j = 0; j < n - 1; j++)
            dfs(heights, m - 1, j, 1);

        vector<vector<int>> ret;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (Pacvisit[i][j] && Atvisit[i][j])
                    ret.push_back({ i,j });

        return ret;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, int flag)//用标记位来表示判断的是哪一个海洋
    {
        if (flag == 0)
            Pacvisit[i][j] = true;
        else
            Atvisit[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j] && ((flag == 0 && !Pacvisit[x][y]) || (flag == 1 && !Atvisit[x][y])))
            {
                dfs(heights, x, y, flag);
            }
        }
    }
};