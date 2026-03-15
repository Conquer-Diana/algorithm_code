#define _CRT_SECURE_NO_WARNINGS

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//二叉树最大宽度
//给你一棵二叉树的根节点 root，返回树的最大宽度 。
//
//树的 最大宽度 是所有层中最大的 宽度 。
//
//每一层的 宽度 被定义为该层最左和最右的非空节点（即两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。
//
//题目数据保证答案将会在  32 位 带符号整数范围内。
//
//示例 1：
//
//输入：root = [1, 3, 2, 5, 3, null, 9]
//输出：4
//解释：最大宽度出现在树的第 3 层，宽度为 4 (5, 3, null, 9) 。
//
//示例 2：
//
//输入：root = [1, 3, 2, 5, null, null, 9, 6, null, 7]
//输出：7
//解释：最大宽度出现在树的第 4 层，宽度为 7 (6, null, null, null, null, null, 7) 。
//
//示例 3：
//
//输入：root = [1, 3, 2, 5]
//输出：2
//解释：最大宽度出现在树的第 2 层，宽度为 2 (3, 2) 。

//采用数组模拟队列的思想，在队列或者数组中存pair，pair里包含该节点以及该节点在数组中的标号（比如root标号为1，左孩子为2x，右孩子为2x+1）
//最后队列前和后的标号的差加1，即为宽度
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

//用队列存pair的方式
class Solution_1 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned int>> q;//随着树高度的增加，标号可能会溢出，但最后两个标号相减的结果会自动更正，但int溢出直接报错，改为unsigned int
        unsigned int ret = 0;
        q.push({ root,1 });

        while (!q.empty())
        {
            auto& [x1, y1] = q.front();
            auto& [x2, y2] = q.back();
            ret = max(ret, y2 - y1 + 1);

            int n = q.size();
            while (n--)
            {
                auto& [x, y] = q.front();
                if (x->left)
                    q.push({ x->left,y * 2 });
                if (x->right)
                    q.push({ x->right,y * 2 + 1 });

                q.pop();
            }
        }

        return ret;
    }
};

//用数组模拟队列存pair的方式
class Solution_2 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*, unsigned int>> q;
        unsigned int ret = 0;
        q.push_back({ root,1 });

        while (q.size())
        {
            auto& [x1, y1] = q[0];
            auto& [x2, y2] = q.back();
            ret = max(ret, y2 - y1 + 1);

            vector<pair<TreeNode*, unsigned int>> tmp;//因为每次头删时间复杂度为O(N)，所以插入下一行节点时，全放到一个临时数组中，结束后将原数组更新为临时数组
            for (auto& [x, y] : q)
            {
                if (x->left)
                    tmp.push_back({ x->left,y * 2 });
                if (x->right)
                    tmp.push_back({ x->right,y * 2 + 1 });
            }
            q = tmp;
        }

        return ret;
    }
};