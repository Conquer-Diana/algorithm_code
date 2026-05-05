#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//分割回文串 II
//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。
//
//返回符合要求的 最少分割次数 。
//
//示例 1：
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成["aa", "b"] 这样两个回文子串。
//
//示例 2：
//输入：s = "a"
//输出：0
//
//示例 3：
//输入：s = "ab"
//输出：1

//这道题需要用常用的以i位置为结尾的dp，但还是需要《回文子串》的dp思路来进行优化
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> fx(n, vector<bool>(n));//存储子串是否为回文串
        vector<int> gx(n, INT_MAX);//gx[i]代表：以i位置为结尾，将前面的字符串分割成回文子串的最小分割次数

        //判断每一个子串是否为回文子串，存在fx[i][j]中
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                if (s[i] == s[j])
                    fx[i][j] = i + 1 < j ? fx[i + 1][j - 1] : true;

        //以i位置为结尾的字符串分为两种情况：
        //1.[0,i]本就是回文串了 -> 不用分割了，分割次数为0
        //2.[0,i]不是回文串  -> 往前枚举j，如果[j,i]是回文串 -> gx[i]就为：以j-1位置为结尾的最小分割次数+分割j-1位置和j位置的那一刀
        //如果[j,i]不是回文串，直接不用判断
        for (int i = 0; i < n; i++)
        {
            if (fx[0][i])
            {
                gx[i] = 0;
                continue;
            }

            for (int j = i; j > 0; j--)//0<j<=i（j=0的情况就是上面的情况，j=i即最后一个字符单独构成回文串，前面的[0,j-1]构成回文串）
            {
                if (fx[j][i])
                    gx[i] = min(gx[i], gx[j - 1] + 1);
            }
        }

        return gx[n - 1];//最后返回gx最后n-1位置的值（字符串末尾）
    }
};