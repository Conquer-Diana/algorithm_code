#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//最后一块石头的重量
//有一堆石头，每块石头的重量都是正整数。
//
//每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
//
//如果 x == y，那么两块石头都会被完全粉碎；
//如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y - x。
//最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

//全部进堆（大根堆）来判断
//每次取出堆顶两个元素相减，不等于0重新进堆，等于0不进堆
//最后当堆里只有一个元素或没有元素时停止，堆大小等于1返回堆顶元素，等于0返回0
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto num : stones)
            pq.push(num);

        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if (y - x != 0)
                pq.push(y - x);
        }

        if (pq.size() == 1)
            return pq.top();
        else
            return 0;
    }
};