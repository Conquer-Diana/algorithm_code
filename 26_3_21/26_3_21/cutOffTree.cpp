#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <vector>
#include <queue>

using namespace std;

//为高尔夫比赛砍树
//你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：
//
//0 表示障碍，无法触碰
//1 表示地面，可以行走
//比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
//每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。
//
//你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。
//
//你将从(0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 - 1 。
//
//可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。
//
//示例 1：
//
//输入：forest = [[1, 2, 3], [0, 0, 4], [7, 6, 5]]
//输出：6
//解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
//
//示例 2：
//
//输入：forest = [[1, 2, 3], [0, 0, 0], [7, 6, 5]]
//输出： - 1
//解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
//
//示例 3：
//
//输入：forest = [[2, 3, 4], [0, 0, 5], [8, 7, 6]]
//输出：6
//解释：可以按与示例 1 相同的路径来砍掉所有的树。
//(0, 0) 位置的树，可以直接砍去，不用算步数。
//
//
//提示：
//
//m == forest.length
//n == forest[i].length
//1 <= m, n <= 50
//0 <= forest[i][j] <= 109

//先将二维数组中的每个数及其下标用一个数据结构都存储起来，然后根据每个元素的值进行排序，这里使用map
//然后从起始点开始，去寻找能到达map中起始点的下一个位置的最短路径，即一次bfs，然后更新起始点和目标位置，直至遍历完map，每两个位置都是最短路径，加起来就是最小和
//这样就将问题转化成了若干个迷宫找出口的问题（若干个bfs）
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    map<int, pair<int, int>> mp;
    bool visit[51][51];
    int m, n;
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size(), n = forest[0].size();
        int ret = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (forest[i][j] > 1)//在这里犯错误了，原来写的是！=0，但题目是'1'不算树，不用砍
                    mp[forest[i][j]] = { i,j };

        int bx = 0, by = 0;
        for (auto& [a, b] : mp)
        {
            int step = nearestExit(forest, bx, by, b.first, b.second);
            if (step == -1)
                return -1;
            ret += step;

            bx = b.first;
            by = b.second;
        }
        return ret;
    }

    int nearestExit(vector<vector<int>>& forest, int bx, int by, int ex, int ey)
    {
        //这一步很重要！！！因为最开始bx，by都是0，但map的最小键值的坐标也可能是（0，0），需要在此直接返回0
        if (bx == ex && by == ey)
            return 0;
        queue<pair<int, int>> q;
        memset(visit, false, sizeof(visit));
        int ret = 1;
        q.push({ bx,by });
        visit[bx][by] = true;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [a, b] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = a + dx[i], y = b + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && forest[x][y] != 0 && !visit[x][y])
                    {
                        if (x == ex && y == ey)
                            return ret;
                        q.push({ x,y });
                        visit[x][y] = true;
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};