#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>

using namespace std;

//01矩阵
//给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
//
//两个相邻元素间的距离为 1 。
//
//示例 1：
//
//输入：mat = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
//输出： [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
//
//示例 2：
//
//输入：mat = [[0, 0, 0], [0, 1, 0], [1, 1, 1]]
//输出： [[0, 0, 0], [0, 1, 0], [1, 2, 1]]

//bfs解决多源（即多个起点）最短路径问题
//解法1：暴力解决，即把多源最短路径问题转换成若干个单源最短路径问题，但这种解法大概率会超时
//解法2：把所有源点当成一个“超级源点”，问题就变成了单一的单源最短路径问题（有严谨的证明，但感性的理解就是，就算把多个起点当成一个起点，其中也会摈弃那些不是最短的路径）
//如何写代码：1.把所有的起点都加入队列中，2.一层一层向外扩 （单源是，把那个唯一起点加入队列，然后一层一层向外扩）

//这道题暴力遍历二维数组的话肯定会超时
//但从1出发去找0的话，不好记录距离
//所以正难则反 将0当成起点去找1，同时用dist数组记录最短路程
//dist数组的存在，就可以不用visit数组，q.size(),step了
class Solution {
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    int m, n;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        //dist作用：当dist[i][j]==-1时，代表没被搜索过
        //当dist[i][j]!=-1,代表最短路径
        vector<vector<int>> dist(m, vector<int>(n, -1));//刚开始全初始化为-1，代表未访问过
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({ i,j });
                }

        //不需要step和q.size()记录bfs到哪一层了，因为dist数组里的数字就代表最短路径以及是哪一层的
        while (!q.empty())
        {
            auto [a, b] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y] == 1 && dist[x][y] == -1)
                {
                    q.push({ x,y });
                    dist[x][y] = dist[a][b] + 1;
                }
            }
        }
        return dist;
    }
};