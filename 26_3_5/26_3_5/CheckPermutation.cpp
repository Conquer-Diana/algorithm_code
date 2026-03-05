#define _CRT_SECURE_NO_WARNINGS

#include <string>

using namespace std;

//判定是否为字符重排
//给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
//
//示例 1：
//
//输入 : s1 = "abc", s2 = "bca"
//输出 : true
//
//示例 2：
//
//输入 : s1 = "abc", s2 = "bad"
//输出 : false

//hash表的基本使用，若是小写字母，26个以内，尽量用数组模拟hash表减小开销
//可以用两个hash表先记录，最后对比两个hash表
//也可以如下面解法用一个hash表，遍历第二个string时，减去对应hash表中的值，减为负数返回false
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;

        int hash[26] = { 0 };

        for (auto ch : s1)
            hash[ch - 'a']++;

        for (auto ch : s2)
            if (--hash[ch - 'a'] < 0)
                return false;

        return true;
    }
};