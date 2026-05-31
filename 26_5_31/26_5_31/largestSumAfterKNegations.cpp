#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>

using namespace std;

//K 次取反后最大化的数组和
//给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
//
//选择某个下标 i 并将 nums[i] 替换为 - nums[i] 。
//重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
//
//以这种方式修改数组后，返回数组 可能的最大和 。
//
//示例 1：
//输入：nums = [4, 2, 3], k = 1
//输出：5
//解释：选择下标 1 ，nums 变为[4, -2, 3] 。
//
//示例 2：
//输入：nums = [3, -1, 0, 2], k = 3
//输出：6
//解释：选择下标(1, 2, 2) ，nums 变为[3, 1, 0, 2] 。
//
//示例 3：
//输入：nums = [2, -3, -1, 5, -4], k = 2
//输出：13
//解释：选择下标(1, 4) ，nums 变为[2, 3, -1, 5, 4] 。


//这道题的贪心策略其实很好想，就是一个分类讨论
//先统计数组中负数的个数，然后与k比较，可以得到
//1.当count < k时，说明可以允许先把数组中所有负数先变为正数，然后剩余出来的k-count次数，如果是偶数，那么在一个数上变化偶数次还是不变，如果是奇数，则需要在已经全变为正数的数组内，选出最小的，将他变为负数，使和最大
//2.当count == k时，计算所有负数变为正数后，数组的总和即可
//3.当count > k时,则需要把前k小的负数变为正数，然后相加，这样贪心即可保证和最大
//由于3中提到到了前k个，我就想到用优先级队列，建立小根堆来求解，但绕了半天，磕磕绊绊终于是解决了哈哈
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int count = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto num : nums)
        {
            pq.push(num);
            if (num < 0)
                count++;
        }

        int ret = 0;
        //1和2放在一起来讨论
        if (count <= k)
        {
            //先计算所有绝对值和
            for (auto num : nums)
                ret += abs(num);
            if ((k - count) % 2 != 0)//如果还有剩余次数
            {
                //先将小根堆里面的负数全部变为正数
                while (pq.top() < 0)
                {
                    int val = pq.top();
                    pq.pop();
                    pq.push(-val);
                }
                //然后用绝对值和减去两倍的最小值即可
                ret -= 2 * pq.top();
            }
        }
        //3
        else if (count > k)
        {
            //计算数组和
            for (auto num : nums)
                ret += num;

            int sum = 0;
            //取出前k个负数最小值，然后求绝对值和
            while (k--)
            {
                sum += abs(pq.top());
                pq.pop();
            }
            //最后的结果是将前k个负数变为正数，所以需要加上两倍的
            sum *= 2;
            ret += sum;
        }
        return ret;
    }
};