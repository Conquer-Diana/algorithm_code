#define _CRT_SECURE_NO_WARNINGS

//二叉搜索树中第K小的结点
//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（k 从 1 开始计数）。
//
//示例 1：
//输入：root = [3, 1, 4, null, 2], k = 1
//输出：1
//
//示例 2：
//输入：root = [5, 3, 6, 2, 4, null, null, 1], k = 3
//输出：3


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}  
};

//与《验证二叉搜索树》一样，采用全局变量，本题采用两个，count用来计数
//重复子问题：中序遍历，直到count==0，返回第K小的元素
class Solution {
    int prev = 0;
    int count;
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        if (root == nullptr)
            return 0;

        prev = kthSmallest(root->left, count);
        if (count == 0)
            return prev;//剪枝

        prev = root->val;
        count--;
        if (count == 0)
            return prev;//剪枝

        prev = kthSmallest(root->right, count);
        return prev;
    }
};