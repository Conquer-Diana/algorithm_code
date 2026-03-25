#define _CRT_SECURE_NO_WARNINGS


#include <unordered_map>
#include <unordered_set>
#include <vector>
#include<string>
#include <queue>

using namespace std;

//火星词典
//现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。
//
//给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
//
//请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。
//
//字符串 s 字典顺序小于 字符串 t 有两种情况：
//
//在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
//如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。
//
//
//示例 1：
//
//输入：words = ["wrt", "wrf", "er", "ett", "rftt"]
//输出："wertf"
//
//示例 2：
//
//输入：words = ["z", "x"]
//输出："zx"
//
//示例 3：
//
//输入：words = ["z", "x", "z"]
//输出：""
//解释：不存在合法字母顺序，因此返回 ""。


//将收集信息的过程抽象为建有向无环图
//收集信息即，两个for循环将words数组中从第一个单词开始从后比较，根据比较规则，定义一个指针向后走即可（比如wrt和wrf比较，得出t->f,er和rftt比较，得出e->r)
//随后进行拓扑排序，找出顺序即可
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> edges;//这里用hash表套hash表的原因是，第二个hash表可以快速查找某一个字母在不在表内
        unordered_map<char, int> in;//入度

        //初始化入度hash表，必须初始化，否则到时候入度++的时候，in中没有对应的字母元素
        for (auto& str : words)
            for (int i = 0; i < str.size(); i++)
                in[str[i]] = 0;

        //收集信息
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                int cur = 0;
                while (cur < words[i].size() && cur < words[j].size())
                {
                    if (words[i][cur] == words[j][cur])
                        cur++;
                    else
                    {
                        //这里解释一下，也是我自己提交时错误的点，我想：unordered_map和unorderd_set不是有去重功能吗，为什么这里还是需要判断
                        //答案显而易见，不判断的话，下面的第一句话是不受影响，但每次入度会多加，也就是说，同一条边，入度会被多加多次，导致结果不正确
                        if (!edges.count(words[i][cur]) || !edges[words[i][cur]].count(words[j][cur]))
                        {
                            edges[words[i][cur]].insert(words[j][cur]);
                            in[words[j][cur]]++;
                        }
                        break;//如果cur指的地方有不相等，加入hash表后直接跳出，不再比较后面
                    }
                }
                //这点也是个大坑，假如前面是abc，后面是ab(即输入[abc,ab])，最后后面指针==ab的长度，但<abc的长度，这种是属于不合法的，不判断继续走最后会返回abc（abc入度都为0，没有边，进队列就弹出来abc），但正确应该返回空
                //即长度长的单词不能作为端单词的前缀
                if (cur != words[i].size() && cur == words[j].size())
                    return "";
            }
        }

        queue<char> q;

        for (auto& [a, b] : in)
            if (b == 0)
                q.push(a);

        string ret;
        while (!q.empty())
        {
            char t = q.front();
            q.pop();
            ret += t;

            for (auto e : edges[t])
            {
                in[e]--;
                if (in[e] == 0)
                    q.push(e);
            }
        }

        for (auto& [a, b] : in)
            if (b)
                return "";
        return ret;
    }
};