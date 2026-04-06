#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>

using namespace std;

//字母大小写全排列
//给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。
//
//返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。
//
//示例 1：
//
//输入：s = "a1b2"
//输出：["a1b2", "a1B2", "A1b2", "A1B2"]
//
//示例 2:
//
//输入: s = "3z4"
//输出 : ["3z4", "3Z4"]
//
//提示 :
//1 <= s.length <= 12
//s 由小写英文字母、大写英文字母和数字组成

//决策树从每个字母无论大小写，不改变或者改变成为分枝，不改变就正常dfs，改变的话就将大写改成小写，小写改成大写，然后dfs
//这种就不用循环，它是按s的顺序依次选择的而不是每一次从头开始选，递归也是一次“循环”
class Solution {
    vector<string> ret;
    string path;
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }

    void dfs(string& s, int pos)
    {
        if (pos == s.size())
        {
            ret.push_back(path);
            return;
        }

        //不改变
        path.push_back(s[pos]);
        dfs(s, pos + 1);
        path.pop_back();

        //改变
        if (s[pos] >= 'A' && s[pos] <= 'z')
        {
            if (s[pos] >= 'a' && s[pos] <= 'z')
            {
                path.push_back(s[pos] + 'A' - 'a');
                dfs(s, pos + 1);
                path.pop_back();
            }
            else
            {
                path.push_back(s[pos] + 'a' - 'A');
                dfs(s, pos + 1);
                path.pop_back();
            }
        }
    }
};