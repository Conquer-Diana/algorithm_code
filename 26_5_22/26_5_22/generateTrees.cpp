#define _CRT_SECURE_NO_WARNINGS

#include <vector>

using namespace std;

//不同的二叉搜索树 II
//给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。
//
//示例 1：
//
//输入：n = 3
//输出： [[1, null, 2, null, 3], [1, null, 3, 2], [2, 1, 3], [3, 1, null, null, 2], [3, 2, null, 1]]
//
//示例 2：
//输入：n = 1
//输出： [[1]]

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//用《不同的二叉搜索树》的思路来解这道题
//这道题由于要把所有的二叉搜索树都构建出来，所以采用回溯
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode*> dfs(int start, int end)
    {
        vector<TreeNode*> path;
        //如果start>end，则返回空树
        if (start > end)
        {
            path.push_back(nullptr);
            return path;
        }

        for (int i = start; i <= end; i++)
        {
            //先将左子树和右子树的所有情况都找出来
            auto l = dfs(start, i - 1);
            auto r = dfs(i + 1, end);

            //将左子树和右子树两两组合，然后与根节点组装
            for (auto ln : l)
            {
                for (auto rn : r)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = ln;
                    root->right = rn;
                    path.push_back(root);
                }
            }
        }
        return path;
    }
};