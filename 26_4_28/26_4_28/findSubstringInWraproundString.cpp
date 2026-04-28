#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using  namespace std;

//环绕字符串中唯一的子字符串
//定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：
//
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。
//
//示例 1：
//输入：s = "a"
//输出：1
//解释：字符串 s 的子字符串 "a" 在 base 中出现。
//
//示例 2：
//输入：s = "cac"
//输出：2
//解释：字符串 s 有两个子字符串("a", "c") 在 base 中出现。
//
//示例 3：
//输入：s = "zab"
//输出：6
//解释：字符串 s 有六个子字符串("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。

class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        //dp[i]表示：以i位置为结尾，子字符串在环绕字符串中出现的次数，因为，一个字母保底会出现一次，所以全初始化为1
        vector<int> dp(n, 1);

        //当前一个字母的ASCII码值+1等于当前字母的ASCII码值，或者前一个字母为z，当前字母为a，dp[i]=dp[i-1]+1（字母本身出现的一次），由于全初始化为1了，所以dp[i]+=dp[i-1]
        for (int i = 1; i < n; i++)
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] += dp[i - 1];

        //返回值这里需要注意，是本题的重点
        //由于末尾字母相同，出现的长的子字符串已经包含了出现的短的子字符串的出现次数，所以需要将dp映射到大小为26的数组中，里面存末尾字母一样的，dp值最大的出现次数
        int arr[26] = { 0 };
        for (int i = 0; i < n; i++)
            arr[s[i] - 'a'] = max(dp[i], arr[s[i] - 'a']);

        //最后返回映射后26个字母的数组中最大dp值的总和
        int ret = 0;
        for (int i = 0; i < 26; i++)
            ret += arr[i];

        return ret;
    }
};

