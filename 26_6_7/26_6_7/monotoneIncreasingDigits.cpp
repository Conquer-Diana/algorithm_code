#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//单调递增的数字
//当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
//给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。
//
//示例 1:
//输入: n = 10
//输出: 9
//
//示例 2:
//输入: n = 1234
//输出: 1234
//
//示例 3:
//输入: n = 332
//输出: 299

//解法一（会超时，当练手）：暴力枚举（就是从n开始往小了去遍历，中间判断是否满足单调递增，满足直接返回）,时间复杂度近似为O(n*logn)，logn为将每一个数字的每一位展开看是否满足递增
//满足单调递增这一步，有两种写法
//1.将数字转成字符串判断
class Solution_1 {
public:
    int monotoneIncreasingDigits(int n) {
        for (int i = n; i >= 0; i--)
        {
            if (IsCreasing(i))
                return i;
        }
        return -1;
    }

    bool IsCreasing(int num)
    {
        string tmp = to_string(num);
        int n = tmp.size();

        for (int i = 0; i < n - 1; i++)
            if (tmp[i] > tmp[i + 1])
                return false;

        return true;
    }
};

//2.用除10，模10的方式不断取最后一位来判断
class Solution_2 {
public:
    int monotoneIncreasingDigits(int n) {
        for (int i = n; i >= 0; i--)
        {
            if (IsCreasing(i))
                return i;
        }
        return -1;
    }

    bool IsCreasing(int num)
    {
        int prev = 0, cur = 0;
        while (num)
        {
            prev = num % 10;
            num /= 10;
            cur = num % 10;
            if (prev < cur)
                return false;
        }
        return true;
    }
};

//解法二：贪心
//贪心策略：举个栗子：n=123454367,从5开始不满足递增的性质了，但是改5前面的数字（高位）的影响比直接改5更大，所以高位如果满足单调递增的话，不去修改
//但是如果改5后面的某一位使其递增的话，整个数就大于n了，不满足要求了，所以贪心策略为将5-1=4，5后面的数全部变为9即可
//但这时候有个bug，比如这样一个数123455554367，是在第四个5那里不满足递增的，但是如果把第四个5-1，后面全部改成9，会发现变成123455549999了，这样反倒从第三个5那里不满足递增了，
//所以找到不递增的位置后，需要往前去找相等的数的第一个位置（没有相等即为原位），将其-1，后面变为9，则正确的为123449999999
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string ret = to_string(n);
        int sz = ret.size(), i = 0;
        while (i < sz - 1 && ret[i] <= ret[i + 1])
            i++;
        if (i + 1 == sz)
            return n;

        while (i - 1 >= 0 && ret[i - 1] == ret[i])
            i--;
        ret[i]--;
        for (int j = i + 1; j < sz; j++)
            ret[j] = '9';

        return stoi(ret);
    }
};