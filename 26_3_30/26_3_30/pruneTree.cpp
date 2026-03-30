#define _CRT_SECURE_NO_WARNINGS


//二叉树剪枝
//给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。
//
//返回移除了所有不包含 1 的子树的原二叉树。
//
//节点 node 的子树为 node 本身加上所有 node 的后代。
//
//示例 1：
//
//输入：root = [1, null, 0, 0, 1]
//输出：[1, null, 0, null, 1]
//解释：
//只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
//
//示例 2：
//
//输入：root = [1, 0, 1, 0, 0, 0, 1]
//输出：[1, null, 1, null, 1]
//示例 3：
//
//
//输入：root = [1, 1, 0, 1, 1, 0, 1, 0]
//输出：[1, 1, 0, 1, 1, null, 1]

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//重复的子问题：判断左右节点是否为空并且自己的值是否为0，是的话返回空，否则就说明有1，就不能剪枝，要保留，返回root
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;//递归出口：当访问到空结点时，默认返回空

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if (root->val == 0 && !root->left && !root->right)
        {
            //delete root;//防止内存泄漏，笔试时可加可不加
            return nullptr;
        }
        return root;
    }
};