#define _CRT_SECURE_NO_WARNINGS


#include <vector>

using namespace std;

//被围绕的区域
//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
//
//连接：一个单元格与水平或垂直方向上相邻的单元格连接。
//区域：连接所有 'O' 的单元格来形成一个区域。
//围绕：如果一个区域中的所有 'O' 单元格都不在棋盘的边缘，则该区域被包围。这样的区域 完全 被 'X' 单元格包围。
//通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。
//
//示例 1：
//
//输入：board = [['X', 'X', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'X', 'O', 'X'], ['X', 'O', 'X', 'X']]
//
//输出： [['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'O', 'X', 'X']]
//
//解释：
//在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。
//
//示例 2：
//
//输入：board = [['X']]
//
//输出： [['X']]

//这道题思路有点跳跃，但很有趣
//即先从四周开始，处理边界情况，将与边界相连的'O'先找个符号来替换，最后总体遍历，将符号改为'O'，将'O'改为'X'
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for (int i = 1; i < m - 1; i++)
        {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '!')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }

    void dfs(vector<vector<char>>& board, int i, int j)
    {
        board[i][j] = '!';
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 1 && x < m - 1 && y >= 1 && y < n - 1 && board[x][y] == 'O')
                dfs(board, x, y);
        }
    }
};