#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <unordered_map>

using namespace std;

//最长定差子序列
//给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 difference 。
//
//子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。
//
//示例 1：
//输入：arr = [1, 2, 3, 4], difference = 1
//输出：4
//解释：最长的等差子序列是[1, 2, 3, 4]。
//
//示例 2：
//输入：arr = [1, 3, 5, 7], difference = 1
//输出：1
//解释：最长的等差子序列是任意单个元素。
//
//示例 3：
//输入：arr = [1, 5, 7, 8, 5, 3, 4, 2, 1], difference = -2
//输出：4
//解释：最长的等差子序列是[7, 5, 3, 1]。

//首先分析，这道题其实也是《最长递增子序列》的变体题，也是可以用熟悉的j去找每一个位置的子序列
//这道题可以用dp[i]表示：以i位置为结尾，最长等差子序列的长度，但分析后发现，j只用从i-1向前遍历找到第一个等差值，将他的dp值+1即为dp[i]（因为，就算前面还有很多等差值，但距离i最近的那个值j，所构成的等差子序列长度是大于等于
//更前面的值的，因为中间可能还有j的等差值，比如示例3，3前面有两个5，但这两个5中间还夹了一个5的等差值7，所以只需要选择距离i最近的那个j即可）
//这里就涉及可以优化的点了，就想到可以将arr[j]的值与dp[j]绑定放入hash表中，这样就不用每次遍历了，推而广之，干脆将每一个arr[i]与其dp[i]都放入hash表中
//所以这道题相当于是在hash表中做动态规划
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        unordered_map<int, int> hash;//arr[i] - dp[i]
        hash[arr[0]] = 1;//初始化将arr[0]对应的dp[0]设为1，其余值为0

        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            //当arr[i] - difference在hash表中不存在时，就相当于是自己构成等差子序列，因为除了arr[0]，其余hash表中的值为0，加1即可
            //当arr[i] - difference在hash表中存在时，就直接用hash表中arr[i] - difference所对应的值+1就为长度（这里arr[i] - difference一定是距离i最近的那个，因为是从左往右遍历的，遍历到最近的等差值时，
            // hash值相较于那些更远的等差值，已经是最新的了）
            hash[arr[i]] = hash[arr[i] - difference] + 1;
            ret = max(ret, hash[arr[i]]);
        }

        return ret;
    }
};