#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

//串联所有单词的子串
//给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。
//
//s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。
//
//例如，如果 words = ["ab", "cd", "ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
//返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。
//
//
//示例 1：
//
//输入：s = "barfoothefoobarman", words = ["foo", "bar"]
//输出：[0, 9]
//解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
//子串 "barfoo" 开始位置是 0。它是 words 中以["bar", "foo"] 顺序排列的连接。
//子串 "foobar" 开始位置是 9。它是 words 中以["foo", "bar"] 顺序排列的连接。
//输出顺序无关紧要。返回[9, 0] 也是可以的。
//
//示例 2：
//
//输入：s = "wordgoodgoodgoodbestword", words = ["word", "good", "best", "word"]
//输出：[]
//解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
//s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
//所以我们返回一个空数组。
//
//示例 3：
//
//输入：s = "barfoofoobarthefoobarman", words = ["bar", "foo", "the"]
//输出：[6, 9, 12]
//解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
//子串 "foobarthe" 开始位置是 6。它是 words 中以["foo", "bar", "the"] 顺序排列的连接。
//子串 "barthefoo" 开始位置是 9。它是 words 中以["bar", "the", "foo"] 顺序排列的连接。
//子串 "thefoobar" 开始位置是 12。它是 words 中以["the", "foo", "bar"] 顺序排列的连接。

//思考“找到字符串中所有的字母异位词”的做法，将words数组中的看成上一题中的字母
//然后改变hash表，left和right的移动步数，以及执行多少次滑动窗口的次数
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words.size();
        int sub_len = words[0].size();

        unordered_map<string, int> hash1;

        for (auto& str : words)
            hash1[str]++;

        int left = 0;
        int right = 0;
        int count = 0;
        vector<int> ret;

        //由于left和right不是一步一步地走的，所以需要执行sub_len次滑动窗口
        for (int i = 0; i < sub_len; i++)
        {
            left = i;
            right = i;
            count = 0;//维护count变量（有效数据）
            unordered_map<string, int> hash2;//每次循环都要把hash2重置

            while (right + sub_len <= s.size())
            {
                string right_str = s.substr(right, sub_len);
                right += sub_len;
                hash2[right_str]++;
                if (hash1.count(right_str) && hash2[right_str] <= hash1[right_str])
                    count++;

                if (right - left > sub_len * len)
                {
                    string left_str = s.substr(left, sub_len);
                    if (hash1.count(left_str) && hash2[left_str] <= hash1[left_str])
                        count--;

                    hash2[left_str]--;
                    left += sub_len;
                }

                if (count == len)
                    ret.emplace_back(left);
            }
        }
        return ret;
    }
};