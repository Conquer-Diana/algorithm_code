#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <queue>

using namespace std;

//在每个树行中找最大值
//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
//
//示例 1：
//
//输入 : root = [1, 3, 2, 5, 3, null, 9]
//输出 : [1, 3, 9]
//
//示例 2：
//
//输入 : root = [1, 2, 3]
//输出 : [1, 3]
//
//示例 3：
//
//输入 : root = [1]
//输出 : [1]
//
//示例 4：
//
//输入 : root = [1, null, 2]
//输出 : [1, 2]
//
//示例 5：
//
//输入 : root = []
//输出 : []

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

//层序遍历（宽搜）的子题目，只要在层序遍历的过程中用变量记录每一行的最大值，最后依次插入数组即可
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ret;
        if (!root)
            return ret;

        q.push(root);
        ret.push_back(root->val);

        while (!q.empty())
        {
            int maxnum = INT_MIN, n = q.size();

            while (n--)
            {
                TreeNode* tn = q.front();
                q.pop();

                if (tn->left)
                {
                    q.push(tn->left);
                    maxnum = max(maxnum, q.back()->val);
                }

                if (tn->right)
                {
                    q.push(tn->right);
                    maxnum = max(maxnum, q.back()->val);
                }
            }

            //如果最后一行都是空结点的话（即队列为空），就不把值传入数组
            if (!q.empty())
                ret.push_back(maxnum);
        }

        return ret;
    }
};