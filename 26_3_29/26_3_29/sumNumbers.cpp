#define _CRT_SECURE_NO_WARNINGS

//求根节点到叶结点的数字之和
//给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
//每条从根节点到叶节点的路径都代表一个数字：
//
//例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
//计算从根节点到叶节点生成的 所有数字之和 。
//
//叶节点 是指没有子节点的节点。
//
//示例 1：
//输入：root = [1, 2, 3]
//输出：25
//解释：
//从根到叶子节点路径 1->2 代表数字 12
//从根到叶子节点路径 1->3 代表数字 13
//因此，数字总和 = 12 + 13 = 25
//
//示例 2：
//输入：root = [4, 9, 0, 5, 1]
//输出：1026
//解释：
//从根到叶子节点路径 4->9->5 代表数字 495
//从根到叶子节点路径 4->9->1 代表数字 491
//从根到叶子节点路径 4->0 代表数字 40
//因此，数字总和 = 495 + 491 + 40 = 1026

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//重复子问题：到一个结点需要把下面左右子树所计算的和加起来返回
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int presum)//此时需要一个前面结点的和作为参数传递下去
    {
        if (root == nullptr)//当叶子节点为空时，则返回0
            return 0;
        if (!root->left && !root->right)//当该节点为叶子节点时，将presum+自己的值返回
            return presum + root->val;

        int sum_l = dfs(root->left, (presum + root->val) * 10);//presum传递给左右子树时，需要先加上该节点的值再*10
        int sum_r = dfs(root->right, (presum + root->val) * 10);
        return sum_l + sum_r;
    }
};