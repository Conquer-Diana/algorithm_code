#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//组合
//给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//
//你可以按 任何顺序 返回答案。
//
//示例 1：
//输入：n = 4, k = 2
//输出：
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]
//
//示例 2：
//输入：n = 1, k = 1
//输出： [[1]]
//
//提示：
//1 <= n <= 20
//1 <= k <= n

//解法1——参考之前的用check数组记录元素是否访问过的解法，但完全可以不用这种剪枝方法
class Solution_1 {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[21];
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ret;
    }

    void dfs(int n, int k, int pos)
    {
        if (path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            //剪枝，把check[i]访问过的或者比当前pos小的剪掉
            if (check[i] == true || i < pos)
                continue;

            path.push_back(i);
            check[i] = true;
            dfs(n, k, i + 1);//每次把当前数字+1作为pos递归下去
            check[i] = false;
            path.pop_back();

        }
    }
};

class Solution_2 {
    vector<vector<int>> ret;
    vector<int> path;
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return ret;
    }

    void dfs(int n, int k, int pos)
    {
        if (path.size() == k)
        {
            ret.push_back(path);
            return;
        }

        //这里直接从pos开始访问，比pos小的就不会进去递归，就相当于剪枝了，更加方便
        for (int i = pos; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k, i + 1);
            path.pop_back();
        }
    }
};