#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//括号生成
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//
//示例 1：
//输入：n = 3
//输出：["((()))", "(()())", "(())()", "()(())", "()()()"]
//
//示例 2：
//输入：n = 1
//输出：["()"]
//
//提示：
//1 <= n <= 8

class Solution {
    vector<string> ret;
    string path;
    int left = 0;
    int right = 0;//用全局变量left和right分别记录左括号和右括号的数量
public:
    vector<string> generateParenthesis(int n) {
        dfs(n);
        return ret;
    }

    void dfs(int n)
    {
        //递归出口：当右括号的数量等于n时，则加入ret（因为先添加的左括号，当右括号满足要求时，左括号一定满足要求）
        if (right == n)
        {
            ret.push_back(path);
            return;
        }

        //当左括号的数量没有达到n时则添加左括号
        if (left < n)
        {
            path += '(';
            left++;
            dfs(n);
            left--;
            path.pop_back();
        }

        //当左括号数量大于右括号数量时，才能添加右括号，这样才符合有效的括号组合
        if (left > right)
        {
            path += ')';
            right++;
            dfs(n);
            right--;
            path.pop_back();
        }
    }
};