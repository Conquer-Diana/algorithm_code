#define _CRT_SECURE_NO_WARNINGS

//假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：
//
//perm[i] 能够被 i 整除
//i 能够被 perm[i] 整除
//给你一个整数 n ，返回可以构造的 优美排列 的 数量 。
//
//示例 1：
//
//输入：n = 2
//输出：2
//解释：
//第 1 个优美的排列是[1, 2]：
//- perm[1] = 1 能被 i = 1 整除
//- perm[2] = 2 能被 i = 2 整除
//第 2 个优美的排列是[2, 1]:
//-perm[1] = 2 能被 i = 1 整除
//- i = 2 能被 perm[2] = 1 整除
//
//示例 2：
//
//输入：n = 1
//输出：1
//
//提示：
//1 <= n <= 15

//用check数组来标记元素是否被访问过
class Solution {
    int ret;
    bool check[16];
public:
    int countArrangement(int n) {
        dfs(n, 1);
        return ret;
    }

    void dfs(int n, int pos)
    {
        if (pos == n + 1)
        {
            ret++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            //剪枝，当元素访问过或者不满足优美排列的关系时，直接跳过
            if (check[i] == true || i % pos != 0 && pos % i != 0)
                continue;

            check[i] = true;
            dfs(n, pos + 1);
            check[i] = false;
        }
    }
};

