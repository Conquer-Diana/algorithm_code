#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//二叉树的锯齿形层序遍历
//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//示例 1：
//
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出： [[3], [20, 9], [15, 7]]
//示例 2：
//
//输入：root = [1]
//输出： [[1]]
//
//示例 3：
//
//输入：root = []
//输出：[]

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

//与N叉树的宽搜类似，不同的是，偶数行的结点插入数组时，需要逆序一下
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        int n = 0, flag = 1;

        if (root == nullptr)
            return ret;

        q.push(root);

        while (!q.empty())
        {
            n = q.size();
            vector<int> tmp;

            while (n--)
            {
                TreeNode* tn = q.front();
                q.pop();
                tmp.push_back(tn->val);
                if (tn->left)
                    q.push(tn->left);
                if (tn->right)
                    q.push(tn->right);
            }
            //偶数行结点插入前逆序
            if (flag % 2 == 0)
                reverse(tmp.begin(), tmp.end());
            flag++;
            ret.push_back(tmp);
        }
        return ret;
    }
};