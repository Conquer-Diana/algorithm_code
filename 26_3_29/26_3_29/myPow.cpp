#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>

using namespace std;

//Pow(x, n)
//实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。
//
//示例 1：
//
//输入：x = 2.00000, n = 10
//输出：1024.00000
//示例 2：
//
//输入：x = 2.10000, n = 3
//输出：9.26100
//示例 3：
//
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2 - 2 = 1 / 22 = 1 / 4 = 0.25


//快速幂
//这道题比如求3^20,要循环20次，幂的次数一高必定会超时
//快速幂的思想就是求3^20，先求3^10,3^5,3^2*3,3^1,3^0,这样时间复杂度就是O(logN）
//细节问题：这题的n可能是负数需要转换为正数并将最终结果用1除以，而且-2^31 <= n <= 2^31-1,当n==-2^31时转换为正数时，会溢出，所以需要转成long long
class Solution {
public:
    double myPow(double x, int n) {
        long long m = abs((long long)n);
        if (n < 0)
            x = 1 / x;

        if (m == 0)
            return 1;//递归出口，当m=0时，返回1

        double tmp = myPow(x, m / 2);

        return m % 2 == 0 ? tmp * tmp : tmp * tmp * x;//如果n是2的倍数，则结果是tmp*tmp，否则结果还需要再多乘一个x

    }
};