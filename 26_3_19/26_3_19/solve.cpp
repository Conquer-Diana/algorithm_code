#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

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
//在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。
//
//示例 2：
//
//输入：board = [['X']]
//
//输出： [['X']]

//FloodFill算法——bfs
//题目的意思是，只有出现在矩阵内部的'O'才能被改为'X'，边缘的及与边缘相连的'O'不能被修改
//解法一：若用直接遍历二维数组的方式，由于是一边遍历，一边修改，如果遇到极端情况，最后才发现这一块区域是与边缘的'O'相连的，则不好还原回去了
//上述情况只能先遍历一遍检查是否合规，然后再遍历一遍进行修改

//解法二：正难则反
//可以先把边缘的'O'找出来进行bfs，将其替换为别的符号'%'，这样矩阵里所剩下的'O'就是要被修改成'X'的，最后再遍历一边矩阵，将'O'改成'X'，将'%'改为'O'即可
//本题可以修改数组，则不可以不用visit数组标记元素是否被遍历过了
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != 0 && i != m - 1 && j != 0 && j != n - 1)
                    continue;
                if (board[i][j] == 'O')
                    bfs(board, i, j);
            }
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '%')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }

    void bfs(vector<vector<char>>& board, int sr, int sc)
    {
        queue<pair<int, int>> q;
        q.push({ sr,sc });
        board[sr][sc] = '%';

        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
                {
                    q.push({ x,y });
                    board[x][y] = '%';
                }
            }
        }
    }
};