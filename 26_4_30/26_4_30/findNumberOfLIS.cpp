#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//最长递增子序列的个数
//给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
//
//注意 这个数列必须是 严格 递增的。
//
//示例 1:
//输入: [1, 3, 5, 4, 7]
//输出 : 2
//解释 : 有两个最长递增子序列，分别是[1, 3, 4, 7] 和[1, 3, 5, 7]。
//
//示例 2 :
//输入 : [2, 2, 2, 2, 2]
//输出 : 5
//解释 : 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        //len[i]代表：以i位置为结尾，最长递增子序列的长度（同《最长递增子序列》）
        //count[i]代表: 以i位置为结尾，最长递增子序列的个数
        //全初始化为1，刚开始长度为1，个数也为1
        vector<int> len(n, 1), count(n, 1);

        int retlen = 1, retcount = 1;
        //这里使用一个小贪心策略：
        //当从一个数组中找到最大值并计数，仅用一次循环遍历找出最大值并计数
        //先让maxval=nums[0]，count=1，当nums[i]==maxval时，count++，当nums[i] > maxval,说明找到了新的最大值，需要重新计数，maxval=nums[i],count=1;
        for (int i = 1; i < n; i++)
        {
            //与《最长递增子序列》一样，i位置的数字需要与前面的以每一个位置为结尾的数字（0，i-1）构成子序列
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    //当某一个j的最长递增子序列长度+1等于i位置的最长递增子序列长度时，与上面的nums[i]==maxval类似，这时候count[i]+=count[j]
                    if (len[j] + 1 == len[i])
                        count[i] += count[j];

                    //当某一个j的最长递增子序列长度+1大于i位置的最长递增子序列长度时，与上面的nums[i] > maxval类似，这时候需要更新len与count
                    else if (len[j] + 1 > len[i])
                    {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }
                }
            }

            //最终结果需要找len中最长的递增子序列长度，所对应的count的总和
            //也可以采用这种贪心策略
            if (retlen == len[i])
                retcount += count[i];
            else if (retlen < len[i])
            {
                retlen = len[i];
                retcount = count[i];
            }
        }
        return retcount;
    }
};