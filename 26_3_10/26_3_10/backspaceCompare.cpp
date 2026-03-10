#define _CRT_SECURE_NO_WARNINGS

#include <string>

using namespace std;

//比较含退格的字符串
//给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
//
//注意：如果对空文本输入退格字符，文本继续为空。
//
//示例 1：
//
//输入：s = "ab#c", t = "ad#c"
//输出：true
//解释：s 和 t 都会变成 "ac"。
//
//示例 2：
//
//输入：s = "ab##", t = "c#d#"
//输出：true
//解释：s 和 t 都会变成 ""。
//
//示例 3：
//
//输入：s = "a#c", t = "b"
//输出：false
//解释：s 会变成 "c"，但 t 仍然是 "b"。

//用栈来模拟即可
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string tmp1, tmp2;

        for (auto ch : s)
        {
            if (ch == '#')
            {
                //文本为空的话，则不退栈
                if (tmp1.size())
                    tmp1.pop_back();
            }
            else
                tmp1 += ch;
        }

        for (auto ch : t)
        {
            if (ch == '#')
            {
                if (tmp2.size())
                    tmp2.pop_back();
            }
            else
                tmp2 += ch;
        }

        if (tmp1 == tmp2)
            return true;
        else
            return false;
    }
};