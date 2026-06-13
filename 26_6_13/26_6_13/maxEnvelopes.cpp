#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>

using namespace std;

//俄罗斯套娃信封问题
//给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
//
//当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
//
//请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
//
//注意：不允许旋转信封。
//
//示例 1：
//输入：envelopes = [[5, 4], [6, 4], [6, 7], [2, 3]]
//输出：3
//解释：最多信封的个数为 3, 组合为: [2, 3] = > [5, 4] = > [6, 7]。
//
//示例 2：
//输入：envelopes = [[1, 1], [1, 1], [1, 1]]
//输出：1

//这道题是《最长递增子序列》的应用题
//解法一：动态规划（会超时），但动态规划之前需要先对数组进行预处理，按左端点进行升序排序（因为遍历j时是往前去找是否能被当前i位置的信封套娃）
//dp[i]表示：以i位置为结尾，最长“套娃序列”的长度
class Solution_1 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        vector<int> dp(n, 1);

        int ret = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])//套娃条件：当宽和高都大于时才可以
                    dp[i] = max(dp[i], dp[j] + 1);

            ret = max(ret, dp[i]);//返回值是dp表内的最大值
        }
        return ret;
    }
};

//解法二：改写排序+贪心+二分
//这道题改写排序后，就能直接转换为《最长递增子序列》
//当左端点不同时，按照左端点升序排序，然后只看右端点进行《最长递增子序列》的操作（因为此时后面的左端点一定比前面的左端点大，只需要看右端点是否大即可）
//当左端点相同时，按照右端点降序排序，然后只看右端点进行《最长递增子序列》的操作（比如,[2,4],[2,6],[2,7],[2,9],如果还按照左端点升序排序的话，就是4，6，7，9，但由于是宽和高都大于时才能套娃，此时宽是相等的，不能套)
//但按照右端点降序排序后，就是9，7，6，4，此时就不可能出现9排在7的后面的情况
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        //改写排序
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] > b[1];
            });

        //贪心+二分
        vector<int> ret;
        ret.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++)
        {
            if (envelopes[i][1] > ret.back())
                ret.push_back(envelopes[i][1]);
            else
            {
                int left = 0, right = ret.size() - 1;
                while (left < right)
                {
                    int mid = (left + right) >> 1;
                    if (envelopes[i][1] > ret[mid])
                        left = mid + 1;
                    else
                        right = mid;
                }
                ret[right] = envelopes[i][1];
            }
        }
        return ret.size();
    }
};

