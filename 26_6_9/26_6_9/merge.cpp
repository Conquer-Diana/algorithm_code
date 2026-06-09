#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>

using namespace std;

//合并区间
//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
//
//示例 1：
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//
//示例 2：
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//
//示例 3：
//输入：intervals = [[4,7],[1,4]]
//输出：[[1,7]]
//解释：区间 [1,4] 和 [4,7] 可被视为重叠区间。


//区间问题解决方法：一般是按左端点或者右端点排序后，找规律去解题
//这道题就是排序+贪心
//按左端点升序排序后，可以得到一个性质：那就是可以合并的区间都是连续的（不会出现跳跃合并的现象，比如说[a1,b1],[a2,b2],[a3,b3], [a1,b1]如果不能与[a2,b2]合并，就一定不能与[a3,b3]合并）
//证明：反证：[a1,b1],[a2,b2].............[ax,bx],假设前两个区间不能合并（能的话，贪心策略一定会合并），但[ax,bx]能与[a1,b1]合并，那可以得出ax<=b1<a2,但是由于是排序好的，a1<a2<ax,这样就矛盾了，所以不能跳跃合并
// 所以一次遍历就能得到所有的合并区间
//贪心策略就是：合并区间实质就是求两个区间的并集
//[left,right] [a,b],当a>right时，没有交叉部分，结果直接插入[left,right]，反之，a<=right时，会分为好几种情况，但结果都一样，都是[left,max(right,b)]
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;

        for (int i = 0; i < n; i++)
        {
            int left = intervals[i][0], right = intervals[i][1], j = i + 1;
            for (; j < n; j++)
            {
                if (intervals[j][0] > right)
                    break;
                else
                    right = max(intervals[j][1], right);
            }
            ret.push_back({ left,right });
            i = j - 1;
        }
        return ret;
    }
};