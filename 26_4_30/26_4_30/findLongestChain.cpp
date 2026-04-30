#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>

using namespace std;

//最长数对链
//给你一个由 n 个数对组成的数对数组 pairs ，其中 pairs[i] = [lefti, righti] 且 lefti < righti 。
//
//现在，我们定义一种 跟随 关系，当且仅当 b < c 时，数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面。我们用这种形式来构造 数对链 。
//
//找出并返回能够形成的 最长数对链的长度 。
//
//你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
//
//示例 1：
//输入：pairs = [[1, 2], [2, 3], [3, 4]]
//输出：2
//解释：最长的数对链是[1, 2] ->[3, 4] 。
//
//示例 2：
//输入：pairs = [[1,2],[7,8],[4,5]]
//输出：3
//解释：最长的数对链是[1, 2] ->[4, 5] ->[7, 8] 。

//这道题由于原数组给的数对，可能是乱序的，比如上面的示例2，[7,8]可以和[1,2]组，也可以和[4,5]组，但由于他的位置在中间，填表的时候不可能同时顾前又顾后，所以需要预处理一下
//预处理就是排序，sort排二维数组时，默认就是按第一个元素大小升序排列，相等再按第二个元素排，符合这个题目的要求
//预处理过后，这道题就与《最长递增子序列》一模一样，不多赘述
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n, 1);

        sort(pairs.begin(), pairs.end());

        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(dp[i], ret);
        }
        return ret;
    }
};