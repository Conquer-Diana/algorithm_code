#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//课程表_2
//现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
//
//例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0, 1] 。
//返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
//
//示例 1：
//输入：numCourses = 2, prerequisites = [[1, 0]]
//输出：[0, 1]
//解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为[0, 1] 。
//
//示例 2：
//输入：numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
//输出：[0, 2, 1, 3]
//解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
//因此，一个正确的课程顺序是[0, 1, 2, 3] 。另一个正确的排序是[0, 2, 1, 3] 。
//
//示例 3：
//输入：numCourses = 1, prerequisites = []
//输出：[0]

//与《课程表》大差不差，只是要求输出的结果不一样
//这道题要求输出拓扑排序的顺序（不唯一）
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> edges;//邻接表存图
        vector<int> in(numCourses);//入度数组

        //建图
        for (auto& arr : prerequisites)
        {
            int a = arr[0], b = arr[1];
            edges[b].push_back(a);
            in[a]++;
        }

        queue<int> q;
        //将入度为0的点加入队列
        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0)
                q.push(i);

        //拓扑排序
        vector<int> ret;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            ret.push_back(t);

            for (auto e : edges[t])
            {
                in[e]--;
                if (in[e] == 0)
                    q.push(e);
            }
        }

        //最后ret的长度等于入度数组的长度，才说明没有环，全进ret了
        if (ret.size() == numCourses)
            return ret;
        else
            return {};
    }
};