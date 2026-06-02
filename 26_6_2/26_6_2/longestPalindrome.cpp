#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//最长回文串
//给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的 回文串 的长度。
//
//在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
//
//示例 1:
//
//输入:s = "abccccdd"
//输出:7
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
//
//示例 2:
//
//输入:s = "a"
//输出:1
//解释：可以构造的最长回文串是"a"，它的长度是 1。

//这一题的贪心策略很简单：就是以中间为分割线，统计字符串中每个字母的个数，如果是偶数，那就直接加上，如果是奇数，可以先减一拿出偶数再相加，此时分割线中间还可以多放一个个数为奇数的多出来的那一个
class Solution {
public:
    int longestPalindrome(string s) {
        //用数组模拟hash表
        int arr[127] = { 0 };
        for (auto x : s)
            arr[x]++;

        int ret = 0;
        for (int i = 0; i < 127; i++)
            ret += arr[i] / 2 * 2;//这里是属于简化代码，是偶数的话，没有影响，是奇数的话，就相当于减了个1（eg：7/2*2=3*2=6)

        return ret < s.size() ? ret + 1 : ret;//最后这步也是一个小简化，如果ret == s.size()，就说明全部字母都是偶数个，如果小于，就说明有奇数个的字母，那就+1
    }
};