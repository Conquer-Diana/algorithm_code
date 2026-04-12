#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//扫雷游戏
//让我们一起来玩扫雷游戏！
//
//给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
//
//'M' 代表一个 未挖出的 地雷，
//'E' 代表一个 未挖出的 空方块，
//'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
//数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
//'X' 则表示一个 已挖出的 地雷。
//给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。
//
//根据以下规则，返回相应位置被点击后对应的盘面：
//
//如果一个地雷（'M'）被挖出，游戏就结束了 - 把它改为 'X' 。
//如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
//如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
//如果在此次点击中，若无更多方块可被揭露，则返回盘面。
//
//示例 1：
//
//输入：board = [["E", "E", "E", "E", "E"], ["E", "E", "M", "E", "E"], ["E", "E", "E", "E", "E"], ["E", "E", "E", "E", "E"]], click = [3, 0]
//输出： [["B", "1", "E", "1", "B"], ["B", "1", "M", "1", "B"], ["B", "1", "1", "1", "B"], ["B", "B", "B", "B", "B"]]
//
//示例 2：
//
//输入：board = [["B", "1", "E", "1", "B"], ["B", "1", "M", "1", "B"], ["B", "1", "1", "1", "B"], ["B", "B", "B", "B", "B"]], click = [1, 2]
//输出： [["B", "1", "E", "1", "B"], ["B", "1", "X", "1", "B"], ["B", "1", "1", "1", "B"], ["B", "B", "B", "B", "B"]]

class Solution {
    //这道题是八个方向，需要拓展一下方向数组
    int dx[8] = { 0,0,-1,1,-1,-1,1,1 };
    int dy[8] = { -1,1,0,0,-1,1,-1,1 };
    int m, n;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size(), n = board[0].size();
        dfs(board, click[0], click[1]);
        return board;
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        //如果给的坐标直接踩雷的话，修改成'X'直接返回
        if (board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return;
        }

        //先统计该坐标周围雷的数量（原本是想把这一步与周围没有雷递归合并到一个循环内，但最后发现，那样不方便将周围有雷的坐标修改成count）
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'M')
                count++;
        }

        //如果有雷，将该位置修改为count返回
        if (count)
        {
            board[i][j] = count + '0';
            return;
        }
        //没有雷的话，进行递归
        else
        {
            board[i][j] = 'B';
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'E')
                    dfs(board, x, y);
            }
        }
    }
};