#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//Z字形转换
//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//
//请你实现这个将字符串进行指定行数变换的函数：
//
//string convert(string s, int numRows);
//
//示例 1：
//
//输入：s = "PAYPALISHIRING", numRows = 3
//输出："PAHNAPLSIIGYIR"
//
//示例 2：
//输入：s = "PAYPALISHIRING", numRows = 4
//输出："PINALSIGYAHRPI"
//解释：
//P     I    N
//A   L S  I G
//Y A   H R
//P     I
//
//示例 3：
//
//输入：s = "A", numRows = 1
//输出："A"

//模拟——99%都是找规律
//利用二维数组（矩阵）找每一行下标的规律
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        int n = s.size();
        string ans;
        int d = 2 * numRows - 2;//每一行的公差

        //先处理第一行
        for (int k = 0; k < n; k += d)
            ans += s[k];

        //处理中间行
        for (int i = 1; i < numRows - 1; i++)
        {
            //中间行是两个为一组向后找规律
            for (int j = i, k = d - i; j < n || k < n; j += d, k += d)//用或者，一个越界，另一个不越界，也要把不越界的加入答案
            {
                //判断是否越界后再加入
                if (j < n) ans += s[j];
                if (k < n) ans += s[k];
            }
        }

        //最后处理最后一行
        for (int i = 0, k = numRows - 1; k + i < n; i += d)
            ans += s[k + i];

        return ans;

    }
};