#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//粉刷房子
//假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。
//
//当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。
//
//例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。
//
//请计算出粉刷完所有房子最少的花费成本。
//
//示例 1：
//输入 : costs = [[17, 2, 17], [16, 16, 5], [14, 3, 19]]
//输出 : 10
//解释 : 将 0 号房子粉刷成蓝色，1 号房子粉刷成绿色，2 号房子粉刷成蓝色。
//最少花费 : 2 + 5 + 3 = 10。
//
//示例 2：
//输入 : costs = [[7, 6, 2]]
//输出 : 2

//这道题属于是三状态了，每一种颜色一种状态，表示以该位置为结尾，该位置填上（红/蓝/绿）色，所对应的最小花费
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int m = costs.size();
        vector<int> red(m + 1), blue(m + 1), green(m + 1);//多开虚拟节点方便初始化

        for (int i = 1; i <= m; i++)
        {
            red[i] = min(blue[i - 1], green[i - 1]) + costs[i - 1][0];//该位置填上红色，则前一个位置只能填蓝色或者绿色，即blue[i-1] or green[i-1] 两者取最小值+cost[red]，其他两种状态以此类推
            blue[i] = min(red[i - 1], green[i - 1]) + costs[i - 1][1];
            green[i] = min(red[i - 1], blue[i - 1]) + costs[i - 1][2];
        }

        return min(min(red[m], blue[m]), green[m]);//最后取最后一个房子对应三种颜色状态的最小值
    }
};