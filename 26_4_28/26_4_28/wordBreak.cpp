#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <unordered_set>
#include <string>

using  namespace std;

//单词拆分
//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
//
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//
//示例 1：
//
//输入 : s = "leetcode", wordDict = ["leet", "code"]
//输出 : true
//解释 : 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
//
//示例 2：
//输入 : s = "applepenapple", wordDict = ["apple", "pen"]
//输出 : true
//解释 : 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//注意，你可以重复使用字典中的单词。
//
//示例 3：
//输入 : s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出 : false

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //优化：先把词典中的单词都丢进hash表里
        unordered_set<string> hash;
        for (auto& word : wordDict)
            hash.insert(word);

        //dp[i]表示：以i位置为结尾，前面的字符串是否能被词典单词拼接出来
        int sz = s.size();
        vector<bool> dp(sz + 1);//默认为false
        dp[0] = true;//第0个位置初始化为true

        s = ' ' + s;//使s的下标整体+1，与dp表对应

        for (int i = 1; i <= sz; i++)
        {
            //以j为分割线，从右往左遍历分割
            //以j-1位置为结尾前面字符串能被拼接成功并且以j位置为开头后面的子串在词典中，则dp[i]为true
            for (int j = i; j >= 1; j--)
            {
                string tmp = s.substr(j, i - j + 1);
                if (dp[j - 1] && hash.count(tmp))
                {
                    dp[i] = true;
                    break;//从右往左找到一种成功的划分方式即标为true后就break
                }
            }
        }
        return dp[sz];
    }
};