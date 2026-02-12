#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//数青蛙
//给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以 croakOfFrogs 中会混合多个 “croak” 。
//
//请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。
//
//要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 - 1 。
//
//示例 1：
//
//输入：croakOfFrogs = "croakcroak"
//输出：1
//解释：一只青蛙 “呱呱” 两次
//
//示例 2：
//
//输入：croakOfFrogs = "crcoakroak"
//输出：2
//解释：最少需要两只青蛙，“呱呱” 声用黑体标注
//第一只青蛙 "crcoakroak"
//第二只青蛙 "crcoakroak"
//
//示例 3：
//
//输入：croakOfFrogs = "croakcrook"
//输出： - 1
//解释：给出的字符串不是 "croak" 的有效组合。

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> index;//[字符，字符的下标]
        string frog = "croak";
        int n = frog.size();
        vector<int> hash(n);//用数组代替hash表

        for (int i = 0; i < n; i++)
            index[frog[i]] = i;

        for (auto ch : croakOfFrogs)
        {
            //如果是字符c，则看前驱字符k在哈希表中是否为0
            //如果为0，则hash（c）正常++
            //若不为0，则从hash（k）中拿出一只青蛙开始，即hash（k）--，hash（c）++
            if (ch == 'c')
            {
                if (hash[n - 1] != 0)
                    hash[n - 1]--;
                hash[0]++;
            }
            //如果是字符r,o,a,k,则看前驱字符在hash表中是否为0
            //若为0，则说明是错误字符
            //若不为0，则将前驱字符--，当前字符++
            else
            {
                int i = index[ch];
                if (hash[i - 1] == 0)
                    return -1;
                hash[i - 1]--;
                hash[i]++;
            }
        }

        //最后得检查hash表中除了k的其他字符在hash表中如果不为0，则错误
        for (int i = 0; i < n - 1; i++)
            if (hash[i] != 0)
                return -1;

        //最后返回hash[k]
        return hash[n - 1];
    }
};