#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <unordered_map>

using namespace std;

//距离相等的条形码
//在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
//
//请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 你可以返回任何满足该要求的答案，此题保证存在答案。
//
//示例 1：
//输入：barcodes = [1, 1, 1, 2, 2, 2]
//输出：[2, 1, 2, 1, 2, 1]
//
//示例 2：
//输入：barcodes = [1, 1, 1, 1, 2, 2, 3, 3]
//输出：[1, 3, 1, 3, 2, 1, 2, 1]

//贪心+模拟
//首先想到，将相同的一组数，隔一个位置填一个，就不会出现相邻相等的情况了
//但这时候先处理谁就成了问题，比如[1,2,2]，先处理1的话，填第一个位置填完了，其余位置只能填2，2，就相等了
//所以可以先处理出现次数最多的那一组数，先把这一组数按照隔一个填一个的方法先填完，其余数怎么处理都是合法的
//证明：首先将这些数分成两两为一组，多出来的一个数单独成一组，则为（n+1）/2组
//这时出现次数最多的那个数，数量一定不超过（n+1）/2个（因为之前是按隔一个填一个的策略，所以每一个二元组内都会有一个该数，如果它大于（n+1）/2个，那么就一定会有一个组内出现相等）
//1.如果出现次数最多的数，数量为（n+1）/2个，那么这时其他数无论怎么填，都不可能相邻，因为都被隔开了
//2.如果出现次数最多的数，数量小于（n+1）/2个，假设此时数量最多的数没有填完：o_o_o_o____,那下一个数开始继续向后填：o_o_o_o_x,当超过数组长度时，重置从前面空位开始填,这时如果x要相邻，是这样的：oxoxoxoxx,
//但此时x的数量就比o多了，与我们先处理数量最多的策略相悖，所以只要先处理数量最多的，后面处理顺序无所谓
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int, int> hash;

        //先记录出现次数最多的那个数以及出现次数
        int maxVal = 0, maxCount = 0;
        for (auto x : barcodes)
        {
            if (maxCount < ++hash[x])
            {
                maxCount = hash[x];
                maxVal = x;
            }
        }

        vector<int> ret(n);
        int index = 0;//先从第一号位开始填数量最多的数
        for (int i = 0; i < maxCount; i++)
        {
            ret[index] = maxVal;
            index += 2;
        }

        //然后处理其余数
        hash.erase(maxVal);
        for (auto& [x, y] : hash)
        {
            for (int i = 0; i < y; i++)
            {
                //当超过数组长度时，重置为二号位开始继续填
                if (index >= n)
                    index = 1;
                ret[index] = x;
                index += 2;
            }
        }
        return ret;
    }
};