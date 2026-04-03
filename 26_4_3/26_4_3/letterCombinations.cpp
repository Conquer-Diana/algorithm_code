#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//电话号码的字母组合
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//  2 -> abc  3 -> def  4 -> ghi  5 -> jkl  6 -> mno
//  7 -> pqrs  8 -> tuv  9 -> wxyz
// 
//示例 1：
//
//输入：digits = "23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//
//示例 2：
//
//输入：digits = "2"
//输出：["a", "b", "c"]

//就是一个排列穷尽问题，只不过需要hash表或者字符串数组来存数字与字符串的映射关系
class Solution {
    string standard[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> ret;
    string path;
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return ret;
        dfs(digits, 0);
        return ret;
    }
    void dfs(string& digits, int pos)
    {
        if (pos == digits.size())
        {
            ret.push_back(path);
            return;
        }

        int tmp = digits[pos] - '0';
        for (int i = 0; i < standard[tmp].size(); i++)
        {
            path += standard[tmp][i];
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }
};