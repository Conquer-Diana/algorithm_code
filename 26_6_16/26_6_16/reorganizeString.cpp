#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//重构字符串
//给定一个字符串 s ，检查是否能重新排布其中的字母，使得两相邻的字符不同。
//
//返回 s 的任意可能的重新排列。若不可行，返回空字符串 "" 。
//
//示例 1:
//输入: s = "aab"
//输出: "aba"
//
//示例 2:
//输入: s = "aaab"
//输出: ""

//字符串版的《距离相等的条形码》——解法一模一样，这里思想和证明过程不再赘述
//贪心+模拟
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> hash;

        //记录出现次数最多的字母以及次数
        char maxVal;
        int maxCount = 0;
        for (auto x : s)
        {
            if (maxCount < ++hash[x])
            {
                maxCount = hash[x];
                maxVal = x;
            }
        }

        //也是证明结果：当出现次数最多的字母个数超过(n + 1) / 2时，一定会出现相邻
        if (maxCount > (n + 1) / 2)
            return "";

        //先处理出现次数最多的的字母，隔一个填一个，从第一位开始填(下标为0）
        string ret;
        ret.resize(n);
        int index = 0;
        for (int i = 0; i < maxCount; i++)
        {
            ret[index] = maxVal;
            index += 2;
        }

        //处理其余字母
        hash.erase(maxVal);
        for (auto& [x, y] : hash)
        {
            for (int i = 0; i < y; i++)
            {
                //当index超过数组长度时，重置为第二位开始继续填（下标为1）
                if (index >= n)
                    index = 1;
                ret[index] = x;
                index += 2;
            }
        }

        return ret;
    }
};