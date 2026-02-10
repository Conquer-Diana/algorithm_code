#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//消失的两个数字
//给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？
//
//以任意顺序返回这两个数字均可。
//
//示例 1：
//
//输入：[1]
//输出：[2, 3]
//
//示例 2：
//
//输入：[2, 3]
//输出：[1, 4]

//解法：本题是消失的数字+只出现一次的数字_3的结合
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int ret = 0;
        int n = nums.size();

        //先把1到n+2的所有数和原数组中的数全部异或，得数为消失的两个数异或的结果
        for (int i = 1; i <= n + 2; i++)
            ret ^= i;

        for (auto x : nums)
            ret ^= x;

        //利用ret & -ret得出异或结果中最右边的1作为分组依据
        int lowbit = ret & -ret;
        vector<int> ans(2);

        //再分别在1到n+2和原数组中根据lowbit分成两组分别异或，两组最后的结果就是消失的两个数
        for (int i = 1; i <= n + 2; i++)
        {
            if ((lowbit & i) == 0)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }

        for (auto x : nums)
        {
            if ((lowbit & x) == 0)
                ans[0] ^= x;
            else
                ans[1] ^= x;
        }

        return ans;

    }
};