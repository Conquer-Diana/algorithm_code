#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//位运算知识补充
//给一个数，确定他的二进制表示中的第x位是0还是1 -> (n>>x)&1
//将一个数n的二进制表示第x位修改成1 -> n|(1<<x)
//将一个数n的二进制表示第x位修改成0 -> n&(~(1<<x))
//提取一个数n中最右侧的1 -> n&(-n) -> lowbit
//干掉一个数n中最右侧的1 -> n&(n-1)

//比特位计数
//给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。
//
//示例 1：
//
//输入：n = 2
//输出：[0, 1, 1]
//解释：
//0 -- > 0
//1 -- > 1
//2 -- > 10
//
//示例 2：
//
//输入：n = 5
//输出：[0, 1, 1, 2, 1, 2]
//解释：
//0 -- > 0
//1 -- > 1
//2 -- > 10
//3 -- > 11
//4 -- > 100
//5 -- > 101

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; i++)
        {
            int ret = 0;
            int mid = i;
            //一直选择干掉右边的1，直到0为止
            while (mid)
            {
                mid &= (mid - 1);
                ret++;
            }
            ans.push_back(ret);
        }

        return ans;
    }
};