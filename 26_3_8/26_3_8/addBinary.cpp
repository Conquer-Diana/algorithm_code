#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>

using namespace std;

//二进制求和
//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
//
//示例 1：
//
//输入 : a = "11", b = "1"
//输出："100"
//示例 2：
//
//输入：a = "1010", b = "1011"
//输出："10101"

//同《链表相加》那道题一样，记录进位，倒序相加
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int t = 0;
        int cur1 = 0, cur2 = 0;
        string ret;

        while (cur1 < a.size() || cur2 < b.size())
        {
            if (cur1 < a.size() && cur2 < b.size())
                t += (a[cur1] - '0') + (b[cur2] - '0');
            if (cur1 >= a.size())
                t += (b[cur2] - '0');
            if (cur2 >= b.size())
                t += (a[cur1] - '0');

            ret += t % 2 + '0';
            t = t / 2;

            cur1++;
            cur2++;
        }
        if (t > 0)
            ret += t + '0';

        reverse(ret.begin(), ret.end());

        return ret;
    }
};