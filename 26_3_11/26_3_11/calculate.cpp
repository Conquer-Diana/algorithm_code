#define _CRT_SECURE_NO_WARNINGS

#include <stack>
#include <string>

using namespace std;

//基本计算器_2
//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//
//整数除法仅保留整数部分。
//
//你可以假设给定的表达式总是有效的。所有中间结果将在[-231, 231 - 1] 的范围内。
//
//注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
//
//示例 1：
//
//输入：s = "3+2*2"
//输出：7
//
//示例 2：
//
//输入：s = " 3/2 "
//输出：1
//
//示例 3：
//
//输入：s = " 3+5 / 2 "
//输出：5

//分情况讨论
//1.字符为操作符：更新操作符
//2.字符为空格：跳过
//3.字符为数字：
//   1.先用循环将（连续或者单个数字）提取出来tmp
//   2.再根据操作符判断：
//     +：将tmp入栈
//     -：将-tmp入栈
//     *：将栈顶元素弹出，与tmp相乘后入栈
//     /：将栈顶元素弹出，与tmp相除后入栈
//最后累加栈中所有元素，即为最后答案
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        char op = '+';

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int tmp = 0, flag = i;
                while (flag < s.size() && s[flag] >= '0' && s[flag] <= '9')
                {
                    tmp = tmp * 10 + (s[flag] - '0');
                    flag++;
                }
                switch (op)
                {
                case '+':
                    nums.push(tmp);
                    break;
                case '-':
                    nums.push(-tmp);
                    break;
                case '*':
                    tmp = nums.top() * tmp;
                    nums.pop();
                    nums.push(tmp);
                    break;
                case '/':
                    tmp = nums.top() / tmp;
                    nums.pop();
                    nums.push(tmp);
                    break;
                default:
                    break;
                }
                //当数字连续，i的位置应该调整到下一个不是数字的字符的前面
                if (flag - 1 != i)
                    i = flag - 1;
            }
            else if (s[i] == ' ')
                continue;
            else
                op = s[i];
        }

        int ret = 0;
        while (!nums.empty())
        {
            ret += nums.top();
            nums.pop();
        }
        return ret;
    }
};