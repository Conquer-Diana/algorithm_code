#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

//判定字符是否唯一
//实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
//
//示例 1：
//
//输入 : s = "leetcode"
//输出 : false
//
//示例 2：
//
//输入 : s = "abc"
//输出 : true
//
//限制：
//0 <= len(s) <= 100
//s[i]仅包含小写字母
//如果你不使用额外的数据结构，会很加分。

//使用位图记录string中的字母，如果当前位为1，则不满足
//位图操作即为判断某一位是否为1，把当前位改为1或0
class Solution {
public:
    bool isUnique(string astr) {
        if (astr.size() > 26)
            return false;

        int bitmap = 0;

        for (auto ch : astr)
        {
            int i = ch - 'a';

            if ((bitmap >> i) & 1 == 1)
                return false;

            bitmap |= (1 << i);
        }
        return true;
    }
};