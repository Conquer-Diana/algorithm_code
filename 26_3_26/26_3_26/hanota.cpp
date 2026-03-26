#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//汉诺塔问题
//
//在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
//(1) 每次只能移动一个盘子;
//(2) 盘子只能从柱子顶端滑出移到下一根柱子;
//(3) 盘子只能叠在比它大的盘子上。
//
//请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。
//
//你需要原地修改栈。
//
//示例 1：
//
//输入：A = [2, 1, 0], B = [], C = []
//输出：C = [2, 1, 0]
//示例 2：
//
//输入：A = [1, 0], B = [], C = []
//输出：C = [1, 0]
//提示：
//
//A 中盘子的数目不大于 14 个。


//递归
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        dfs(A, B, C, n);
    }

    void dfs(vector<int>& x, vector<int>& y, vector<int>& z, int n)
    {
        if (n == 1)
        {
            z.push_back(x.back());//这里不能写成x[0]
            x.pop_back();
            return;
        }

        dfs(x, z, y, n - 1);
        z.push_back(x.back());//这里也一样不能写成x[0]，因为宏观上看是把上面的n-1个盘子借助z柱子放到x柱子上了，最后不就剩下最后一个x[0]吗？但是递归到深处，实际上是先将最上面的盘子借助一个柱子放到另一个柱子
        //写成x[0]的话，就成先移动最底下的盘子了
        x.pop_back();
        dfs(y, x, z, n - 1);
    }
};