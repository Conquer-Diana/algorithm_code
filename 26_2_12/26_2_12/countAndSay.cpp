#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//「外观数列」是一个数位字符串序列，由递归公式定义：
//
//countAndSay(1) = "1"
//countAndSay(n) 是 countAndSay(n - 1) 的行程长度编码。
//
//
//行程长度编码（RLE）是一种字符串压缩方法，其工作原理是通过将连续相同字符（重复两次或更多次）替换为字符重复次数（运行长度）和字符的串联。例如，要压缩字符串 "3322251" ，我们将 "33" 用 "23" 替换，将 "222" 用 "32" 替换，将 "5" 用 "15" 替换并将 "1" 用 "11" 替换。因此压缩后字符串变为 "23321511"。
//
//给定一个整数 n ，返回 外观数列 的第 n 个元素。
//
//示例 1：
//
//输入：n = 4
//
//输出："1211"
//
//解释：
//
//countAndSay(1) = "1"
//
//countAndSay(2) = "1" 的行程长度编码 = "11"
//
//countAndSay(3) = "11" 的行程长度编码 = "21"
//
//countAndSay(4) = "21" 的行程长度编码 = "1211"
//
//示例 2：
//
//输入：n = 1
//
//输出："1"
//
//解释：
//
//这是基本情况。

//模拟+双指针
class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";//初始状态

        for (int i = 1; i < n; i++)//翻译n - 1次
        {
            string tmp;
            int left = 0;
            int right = 0;
            int count = 0;

            //双指针，找相同类型的，计数并计入tmp
            while (right < ret.size())
            {
                while (right < ret.size() && ret[right] == ret[left])
                    right++;

                count = right - left;
                tmp += to_string(count) + ret[left];
                left = right;
            }
            ret = tmp;//将tmp赋给ret，再次进行下一次翻译
        }

        return ret;
    }
};