#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//增减字符串匹配
//由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:
//
//如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
//如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
//给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
//
//示例 1：
//输入：s = "IDID"
//输出：[0,4,1,3,2]
//
//示例 2：
//输入：s = "III"
//输出：[0,1,2,3]
//
//示例 3：
//输入：s = "DDI"
//输出：[3,2,0,1]

//这道题的贪心策略是：遇到'I'就是选当前的最小值，遇到'D'就选当前的最大值（因为遇到'I'选最小值后，后面的那一个不管如何选择，都能呈现上升趋势，同理，遇到'D'选最大值后，后面的那一个不管如何选择，都能呈现下降趋势）
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int maxn = n, minn = 0;
        vector<int> ret;

        //利用双指针不断向中间收缩即可
        for (auto x : s)
        {
            if (x == 'I')
                ret.push_back(minn++);
            else
                ret.push_back(maxn--);
        }
        //最后由于还差一个数，但此时max和min是相等的，直接插入即可
        ret.push_back(maxn);
        return ret;
    }
};