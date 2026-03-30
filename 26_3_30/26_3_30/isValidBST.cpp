#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

//验证二叉搜索树
//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//
//有效 二叉搜索树定义如下：
//
//节点的左子树只包含 严格小于 当前节点的数。
//节点的右子树只包含 严格大于 当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。
//
//示例 1：
//
//输入：root = [2, 1, 3]
//输出：true
//
//示例 2：
//
//输入：root = [5, 1, 4, null, null, 3, 6]
//输出：false
//解释：根节点的值是 5 ，但是右子节点的值是 4 。

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//二叉搜索树的中序遍历就是一个有序数列
//重复子问题：先判断左子树是否为二叉搜索树，再将prev的值更新为自己结点的值，再判断右子树是否为二叉搜索树，最后返回两个bool值的与
class Solution {
    long prev = LONG_MIN;//定义全局变量prev，表示中序遍历该节点前驱结点的值，用于判断二叉搜索树是否合规
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;//递归出口：如果访问节点为空，则直接返回true，即当只有一个结点的树也是二叉搜索树

        bool left = isValidBST(root->left);
        if (!left)
            return false;//剪枝，当左子树已经不是二叉搜索树了，直接一直向上返回false即可，下面的根节点和右子树可以不用看了

        if (root->val > prev)
            prev = root->val;
        else
            return false;//剪支，当根节点的值不满足二叉搜索树的要求时，也直接向上返回false，下面的右子树可以不用看了，提高搜索效率

        bool right = isValidBST(root->right);

        return left && right;
    }
};