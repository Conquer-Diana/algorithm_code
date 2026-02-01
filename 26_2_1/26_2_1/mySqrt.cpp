#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//x的平方根
//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//
//由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
//
//注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x** 0.5 。
//
//示例 1：
//输入：x = 4
//输出：2
//
//示例 2：
//输入：x = 8
//输出：2
//解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。

//根据二段性，划分为mid*mid<=和>两个区间
class Solution {
public:
    int mySqrt(int x) {

        if (x < 1)
            return 0;

        long long left = 1;
        long long right = x;

        while (left < right)
        {
            long long mid = left + (right - left + 1) / 2;//防溢出

            if (mid * mid > x)
                right = mid - 1;
            else
                left = mid;
        }

        return left;
    }
};