#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <string>

using namespace std;

//二叉树的所有路径
//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//
//叶子节点 是指没有子节点的节点。
//
//示例 1：
//输入：root = [1, 2, 3, null, 5]
//输出：["1->2->5", "1->3"]
//
//示例 2：
//输入：root = [1]
//输出：["1"]

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<string> ret;//全局变量
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;//这里的path如果也设置成全局变量，就需要“恢复现场”
        //注意：有回溯（dfs），就必有恢复现场
        dfs(root, path);
        return ret;
    }

    //重复子问题：前序遍历，如果为叶子结点，只加本身值放进全局vector
    //不为叶子节点，加入本身值和"->"
    void dfs(TreeNode* root, string path)//这里path作为形参，每一层的path都是全新的，不会影响上一层的path，属于“自动化”，不用恢复现场
    {
        if (!root->left && !root->right)
        {
            path += to_string(root->val);
            ret.push_back(path);
            return;
        }

        path += to_string(root->val) + "->";
        if (root->left)
            dfs(root->left, path);//剪枝

        //如果path设置为全局的，应该在这里恢复现场，不能让dfs影响到path

        if (root->right)
            dfs(root->right, path);//剪枝
        return;
    }
};