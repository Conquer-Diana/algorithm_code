#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

//最小基因变化
//基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
//
//假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
//
//例如，"AACCGGTT" -- > "AACCGGTA" 就是一次基因变化。
//另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
//
//给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 - 1 。
//
//注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。
//
//示例 1：
//
//输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
//输出：1
//
//示例 2：
//
//输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
//输出：2
//
//示例 3：
//
//输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
//输出：3

//提示：
//
//start.length == 8
//end.length == 8
//0 <= bank.length <= 10
//bank[i].length == 8
//start、end 和 bank[i] 仅由字符['A', 'C', 'G', 'T'] 组成

//本题将每一个基因序列抽象为一个点，每一步的基因变化抽象为图的一条边，则本题就是边权为1的最短路问题
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //用hash来表示基因库bank，用来判断变化的基因序列是否在基因库中，从而筛选出可以插入队列的基因序列
        //用visit来表示，该基因序列是否被访问过了
        unordered_set<string> hash, visit;
        queue<string> q;
        int ret = 1;
        string change = "ACGT";//用来枚举所有的变化情况
        q.push(startGene);
        visit.insert(startGene);

        if (startGene == endGene)
            return 0;

        for (auto gene : bank)
            hash.insert(gene);

        if (!hash.count(endGene))
            return -1;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                string src = q.front();
                q.pop();

                //从源字符串的第一个字母开始，依次替换为"ACGT"，看是否在基因库中且是否没被访问过，从而插入队列，作为下一趟中队列的结点
                for (int i = 0; i < src.size(); i++)
                {
                    string tmp = src;
                    for (int j = 0; j < change.size(); j++)
                    {
                        tmp[i] = change[j];
                        if (hash.count(tmp) && !visit.count(tmp))
                        {
                            //如果走到终点，即返回扩展的层数ret
                            if (tmp == endGene)
                                return ret;
                            q.push(tmp);
                            visit.insert(tmp);
                        }
                    }
                }
            }
            ret++;
        }
        return -1;
    }
};