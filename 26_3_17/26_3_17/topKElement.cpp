#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

//前K个高频元素
//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
//
//示例 1：
//
//输入：nums = [1, 1, 1, 2, 2, 3], k = 2
//
//输出：[1, 2]
//
//示例 2：
//
//输入：nums = [1], k = 1
//
//输出：[1]
//
//示例 3：
//
//输入：nums = [1, 2, 1, 2, 1, 2, 3, 1, 3, 2], k = 2
//
//输出：[1, 2]

//与《前K个高频单词》同样的解法
class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
        {
            return p1.second > p2.second;
        }
    };

    vector<int> topKElement(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        for (auto num : nums)
            hash[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (auto& kv : hash)
        {
            pq.push(kv);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ret;
        while (!pq.empty())
        {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};