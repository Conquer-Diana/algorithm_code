#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>

using namespace std;

//优势洗牌（田忌赛马）
//给定两个长度相等的数组 nums1 和 nums2，nums1 相对于 nums2 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。
//返回 nums1 的 任意 排列，使其相对于 nums2 的优势最大化。
//
//示例 1：
//输入：nums1 = [2, 7, 11, 15], nums2 = [1, 10, 4, 11]
//输出：[2, 11, 7, 15]
//
//示例 2：
//输入：nums1 = [12, 24, 8, 32], nums2 = [13, 25, 32, 11]
//输出：[24, 32, 8, 12]
//
//提示：
//1 <= nums1.length <= 105
//nums2.length == nums1.length
//0 <= nums1[i], nums2[i] <= 109

//这道题就是田忌赛马
//来回顾一下：
//将齐威王和田忌的马按质量升序排序：
//田：下 中 上
//齐：下 中 上
//因为齐威王的马在同等质量上都大于田忌，所以每次用同等质量的马去比必败，所以有如此策略：
//由于田忌的下等马是比不过的齐威王的下等马的，所以就考虑用下等马去消耗掉王的上等马，但田忌的中等马略胜与王的下等马，所以直接将其斩于马下，最后田忌用上等马赢过王的中等马也是板上钉钉的事
//田：中 上 下

//有这个策略作为启发，来用一个示例演示一下
//nums1 = [12, 24, 8, 32] 升序——> [8, 12, 24, 32]
//nums2 = [13, 25, 32, 11] 升序——> [11, 13, 25, 32]
//最开始 8 < 11,所以直接用8去消耗掉nums2中的最强战力32（此时ret[x,x,x,8]),然后到12与11，12 > 11，比得过直接拿下11（此时ret[12,x,x,8]),随后的24与13，32与25都是直接拿下（此时ret[12,24,32,8])
//但此时发现ret[12,24,32,8]与答案的[24, 32, 8, 12]不一样，那是因为，我们是在nums2被升序排序后做的赛马，顺序肯定不对，所以这时候上一题《按身高排序》的解法3思想就发挥作用了，就是创建nums2的下标数组，排序去排下标数组即可
//总结贪心策略：
//比得过，直接将其拿下
//比不过，直接去消耗掉nums2中的最强战力
//由于是升序，最强战力在最后，所以需要用到双指针分别指向nums2的前和后
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        //下标数组
        vector<int> index2(n);
        for (int i = 0; i < n; i++)
            index2[i] = i;

        //升序排序
        sort(nums1.begin(), nums1.end());
        sort(index2.begin(), index2.end(), [&](int i, int j) {
            return nums2[i] < nums2[j];
            });

        int left = 0, right = n - 1;
        vector<int> ret(n);
        for (int i = 0; i < n; i++)
        {
            //比不过（注意：相等的情况也是属于比不过，想想齐威王和田忌的质量相等的马o(*￣▽￣*)o，所以就算相等也选择去消耗最强战力）
            if (nums1[i] <= nums2[index2[left]])
                ret[index2[right--]] = nums1[i];//由于排序的是nums2的下标数组，所以需要去找的是index2[right]的那个位置将nums1[i]放入
            else
                ret[index2[left++]] = nums1[i];
        }
        return ret;
    }
};