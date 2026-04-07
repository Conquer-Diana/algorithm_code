#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//N皇后
//按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
//
//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//
//给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
//
//每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
//
//示例 1：
//
//输入：n = 4
//输出： [[".Q..", "...Q", "Q...", "..Q."], ["..Q.", "Q...", "...Q", ".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
//
//示例 2：
//
//输入：n = 1
//输出： [["Q"]]

//这道题做完真的有种意犹未尽的感觉，剪枝的思想设计的非常之巧妙
//决策树的思想其实就是每次给一个行数（row），依次遍历这个行的每一列（col），在其中安插皇后，再枚举下一行
class Solution {
    vector<vector<string>> ret;
    vector<string> path;
    bool col[10];//列
    bool dig1[20];//主对角线
    bool dig2[20];//副对角线
public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n);
        for (int i = 0; i < n; i++)
            path[i].append(n, '.');

        dfs(n, 0);
        return ret;
    }

    void dfs(int n, int row)
    {
        //当行数row遍历到实际行数下一个位置（下标为0—n-1），即n时，加入结果ret中
        if (row == n)
        {
            ret.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            //剪枝规则，首先该行有没有皇后可以不用判断，因为每次dfs只在该行放一个皇后
            //第一种办法可以暴力查看当前位置的那一列，主对角线，和副对角线是否有皇后，但这样每次都需要三个循环判断，太过复杂
            //第二种办法即下面的优化——利用三个布尔数组，分别判断列，主对角线，副对角线是否有皇后
            //主对角线借助数学中直线斜率，为y=x+b，即y-x=b，在这条对角线的每一个点的列-行都等于一个常数，但有时候列-行会等于负数，所以为了让bool数组下标能满足全部情况，列-行再+n，这样全部都是正数
            //副对角线的直线方程为：y=-x+b,即y+x=b，行+列=常数，这时候全为正数，就不用+n

            //剪枝——即该列或所在的主对角线或者所在的副对角线==true时，跳过，即剪枝
            if (col[i] == true || dig1[i - row + n] == true || dig2[i + row] == true)
                continue;

            path[row][i] = 'Q';
            col[i] = true;
            dig1[i - row + n] = true;
            dig2[i + row] = true;
            dfs(n, row + 1);
            //恢复现场
            path[row][i] = '.';
            col[i] = false;
            dig1[i - row + n] = false;
            dig2[i + row] = false;
        }
    }
};