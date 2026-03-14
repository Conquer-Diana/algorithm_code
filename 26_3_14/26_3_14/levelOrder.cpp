#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>

using namespace std;

//N叉树的层序遍历
//给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//
//树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。
//
//示例 1：
//
//
//输入：root = [1, null, 3, 2, 4, null, 5, 6]
//输出： [[1], [3, 2, 4], [5, 6]]
//
//示例 2：
//
//输入：root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14]
//输出： [[1], [2, 3, 4, 5], [6, 7, 8, 9, 10], [11, 12, 13], [14]]

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//宽度优先搜索（层序遍历）BFS
//利用队列的特性实现
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ret;
        int n = 0;

        if (root == nullptr)
            return ret;

        q.push(root);

        while (!q.empty())
        {
            n = q.size();//统计本层结点的个数
            vector<int> tmp;//本层结点的数组
            while (n--)//让本层结点依次出队
            {
                tmp.push_back(q.front()->val);
                for (auto& child : q.front()->children)//出队之前，将该节点的孩子结点入队
                    if (child)
                        q.push(child);
                q.pop();
            }
            ret.push_back(tmp);
        }

        return ret;
    }
};

