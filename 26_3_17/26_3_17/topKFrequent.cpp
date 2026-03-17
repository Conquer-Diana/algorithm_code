#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

//前K个高频单词
//给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。
//
//返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字典顺序排序。//这句话是本题重点，意味着频次不同，用小根堆排，频次相同，根据字典顺序降序排，用大根堆
//
//示例 1：
//
//输入 : words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出 : ["i", "love"]
//解析 : "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//注意，按字母顺序 "i" 在 "love" 之前。
//
//示例 2：
//
//输入 : ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"] , k = 4
//输出 : ["the", "is", "sunny", "day"]
//解析 : "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//出现次数依次为 4, 3, 2 和 1 次。

class Solution {
public:
    //重中之重，实现比较函数
    struct Compare
    {
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
        {
            return (p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first));
            //频次不同时，小根堆是谁大谁往下
            //频次相同时，大根堆是谁小谁往下
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        //先用hash表统计单词出现的频次
        unordered_map<string, int> hash;

        for (auto& s : words)
            hash[s]++;

        //创建堆，其中存pair，主要是实现仿函数比较
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

        //依次进堆，大于k弹出
        for (auto kv : hash)
        {
            pq.push(kv);
            if (pq.size() > k)
                pq.pop();
        }

        //最后的结果由于是小根堆，堆中频次最低的在堆顶，而题目要求要从高到低，所以要倒着插入数组
        vector<string> ret(k);
        int i = k - 1;
        while (!pq.empty())
        {
            ret[i--] = pq.top().first;
            pq.pop();
        }

        return ret;
    }
};