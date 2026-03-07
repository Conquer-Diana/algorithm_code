#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>

using namespace std;

//最长公共前缀
//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1：
//
//输入：strs = ["flower", "flow", "flight"]
//输出："fl"
//
//示例 2：
//
//输入：strs = ["dog", "racecar", "car"]
//输出：""
//解释：输入不存在公共前缀。

//解法一：两两比较
class Solution_1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = strs[0];

        for (int i = 1; i < strs.size(); i++)
            ret = findCommon(ret, strs[i]);

        return ret;
    }

    string findCommon(string& s1, string& s2)
    {
        int i = 0;
        while (i < min(s1.size(), s2.size()) && s1[i] == s2[i])
            i++;
        return s1.substr(0, i);
    }
};

//解法二：总体比较
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;

        //以第一个字符串为标准
        for (int i = 0; i < strs[0].size(); i++)
        {
            char standard = strs[0][i];

            int j = 0;
            for (j = 1; j < strs.size(); j++)
                if (strs[j][i] != standard)
                    break;

            if (j == strs.size())
                ret += strs[0][i];
            else
                break;
        }
        return ret;
    }
};