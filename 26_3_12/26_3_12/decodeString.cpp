#define _CRT_SECURE_NO_WARNINGS

#include <stack>
#include <string>

using namespace std;

//字符串解码
//给定一个经过编码的字符串，返回它解码后的字符串。
//
//编码规则为 : k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
//
//测试用例保证输出的长度不会超过 105。
//
//示例 1：
//
//输入：s = "3[a]2[bc]"
//输出："aaabcbc"
//
//示例 2：
//
//输入：s = "3[a2[c]]"
//输出："accaccacc"
//
//示例 3：
//
//输入：s = "2[abc]3[cd]ef"
//输出："abcabccdcdcdef"
//
//示例 4：
//
//输入：s = "abc3[cd]xyz"
//输出："abccdcdcdxyz"

//用双栈来模拟，一个栈存字符串，一个栈存数字
//以 1[a2[bc]]de3[f]来举例
//会出现以下情况：
// 1. 数字：将数字提取出来压入数字栈中
// 2. “[”：将左括号后边的字符串提取出来，压入字符串栈中
// 3. “]”：将两个栈的栈顶元素都弹出进行解码，结果放到字符串栈中栈顶字符串的后面
// 4. 前面没有"["的字符串：提取出来直接放到字符串栈中栈顶字符串的后面

//最后返回字符串栈栈顶元素即为答案
class Solution {
public:
    string decodeString(string s) {
        stack<string> str;
        stack<int> num;

        str.push("");

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '1' && s[i] <= '9')
            {
                int tmp = 0, flag = i;
                while (s[flag] >= '0' && s[flag] <= '9')
                {
                    tmp = tmp * 10 + (s[flag] - '0');
                    flag++;
                }
                num.push(tmp);

                if (flag - 1 != i)
                    i = flag - 1;
            }
            else if (s[i] == '[')
            {
                string tmp;
                int flag = i + 1;
                while (s[flag] >= 'a' && s[flag] <= 'z')
                {
                    tmp += s[flag];
                    flag++;
                }
                str.push(tmp);

                i = flag - 1;
            }
            else if (s[i] == ']')
            {
                //解码的过程即为字符串栈栈顶元素+=(数字栈栈顶元素-1)次的字符串栈栈顶元素
                int op = num.top() - 1;
                num.pop();
                string tmp = str.top();
                str.pop();
                string temp = tmp;

                while (op--)
                    temp += tmp;

                str.top() += temp;
            }
            else
            {
                string tmp;
                int flag = i;
                while (flag<s.size() && s[flag] >= 'a' && s[flag] <= 'z')
                {
                    tmp += s[flag];
                    flag++;
                }
                str.top() += tmp;

                if (flag - 1 != i)
                    i = flag - 1;
            }
        }
        return str.top();
    }
};