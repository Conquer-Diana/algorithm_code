#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//单词搜索
//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//示例 1：
//
//输入：board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']], word = "ABCCED"
//输出：true
//
//示例 2：
//
//输入：board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']], word = "SEE"
//输出：true
//
//示例 3：
//
//输入：board = [['A', 'B', 'C', 'E'], ['S', 'F', 'C', 'S'], ['A', 'D', 'E', 'E']], word = "ABCB"
//输出：false

class Solution {
    int m, n;
    //方向数组
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    bool visit[7][7];
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        //找到起始位置（即word[0]，不止一个，要在循环里递归）
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0])
                {
                    visit[i][j] = true;
                    if (dfs(board, i, j, word, 1))
                        return true;
                    visit[i][j] = false;
                }

        return false;//如果上面的循环都没返回true，则说明结果不存在
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int pos)
    {
        if (pos == word.size())
            return true;
        //从传递过来的位置从上下左右开始拓展
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == word[pos] && !visit[x][y])//满足：不越界，等于word[pos]，且未被访问过，则继续
            {
                visit[x][y] = true;
                //要用dfs的返回值来作为判断条件，如果返回false，则略过此点
                if (dfs(board, x, y, word, pos + 1))
                    return true;
                visit[x][y] = false;
            }
        }
        return false;//当一个位置上下左右都不满足条件，则返回false
    }
};