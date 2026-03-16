#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>

using namespace std;

//数据流中的第K个大元素
//设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
//
//请实现 KthLargest 类：
//
//KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
//int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
//
//示例 1：
//
//输入：
//["KthLargest", "add", "add", "add", "add", "add"]
//[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
//
//输出：[null, 4, 5, 5, 8, 8]
//
//解释：
//
//KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
//kthLargest.add(3); // 返回 4
//kthLargest.add(5); // 返回 5
//kthLargest.add(10); // 返回 5
//kthLargest.add(9); // 返回 8
//kthLargest.add(4); // 返回 8
//
//示例 2：
//
//输入：
//["KthLargest", "add", "add", "add", "add"]
//[[4, [7, 7, 7, 7, 8, 3]], [2], [10], [9], [9]]
//
//输出：[null, 7, 7, 7, 8]
//
//解释：
//
//KthLargest kthLargest = new KthLargest(4, [7, 7, 7, 7, 8, 3]);
//kthLargest.add(2); // 返回 7
//kthLargest.add(10); // 返回 7
//kthLargest.add(9); // 返回 7
//kthLargest.add(9); // 返回 8

//Top-K问题的应用
//第k大->用小根堆，第k小->用大根堆
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto num : nums)
            pq.push(num);
        while (pq.size() > k)
            pq.pop();
        K = k;
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};