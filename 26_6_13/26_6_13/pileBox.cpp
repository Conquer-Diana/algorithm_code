#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>

using namespace std;

//面试题 08.13.堆箱子
//堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最高的一堆箱子。箱堆的高度为每个箱子高度的总和。
//输入使用数组[wi, di, hi]表示每个箱子。
//
//示例 1：
//输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
//输出：6
//
//示例 2：
//输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
//输出：10
//
//提示 :
//箱子的数目不大于3000个。

//就是用《俄罗斯套娃信封问题》超时的动态规划解法就能解决这道题，只不过问法不一样
//需要先对数组进行预处理，按左端点进行升序排序（因为遍历j时是往前去找是否能叠放到当前i位置上面）
class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end());
        int n = box.size();
        vector<int> dp(n);
        dp[0] = box[0][2];

        int ret = dp[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += box[i][2];//找的是最高的高度
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};