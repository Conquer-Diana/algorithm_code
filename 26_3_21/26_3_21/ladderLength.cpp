#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include<string>
#include <vector>
#include <unordered_set>

using namespace std;

//单词接龙
//在字典（单词列表） wordList 中，从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：
//
//序列中第一个单词是 beginWord 。
//序列中最后一个单词是 endWord 。
//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典 wordList 中的单词。
//给定两个长度相同但内容不同的单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。
//
//示例 1：
//
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//输出：5
//解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
//
//示例 2：
//
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot", "dot", "dog", "lot", "log"]
//输出：0
//解释：endWord "cog" 不在字典中，所以无法进行转换。
//
//提示：
//
//1 <= beginWord.length <= 10
//endWord.length == beginWord.length
//1 <= wordList.length <= 5000
//wordList[i].length == beginWord.length
//beginWord、endWord 和 wordList[i] 由小写英文字母组成
//beginWord != endWord
//wordList 中的所有字符串 互不相同

//与《最小基因变化》一模一样
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //哈希表将单词字典插入，方便查找
        unordered_set<string> hash(wordList.begin(), wordList.end());
        //visit记录是否被访问过
        unordered_set<string> visit;
        queue<string> q;
        int ret = 1;
        q.push(beginWord);
        visit.insert(beginWord);
        ret++;

        if (beginWord == endWord)
            return 2;
        if (!hash.count(endWord))
            return 0;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string src = q.front();
                q.pop();

                //从每个单词的第一个位置开始，依次替换为a到z，单词在字典中有且未被访问过则加入队列
                for (int i = 0; i < src.size(); i++)
                {
                    string tmp = src;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        tmp[i] = ch;
                        if (hash.count(tmp) && !visit.count(tmp))
                        {
                            //若其中单词直接与最后的目标词一样，直接返回
                            if (tmp == endWord)
                                return ret;
                            q.push(tmp);
                            visit.insert(tmp);
                        }
                    }
                }
            }
            ret++;
        }
        return 0;
    }
};