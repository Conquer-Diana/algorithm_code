#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例 1：
//
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//
//示例 2：
//
//输入：l1 = [], l2 = []
//输出：[]
//
//示例 3：
//
//输入：l1 = [], l2 = [0]
//输出：[0]

//递归版
//相同的子问题，先比大小，然后相同的子问题即将小的节点后面和另一个链表继续合并
//递归出口：当l1为空，返回l2，l2为空，返回l1
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return dfs(list1, list2);
    }

    ListNode* dfs(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val <= l2->val)
        {
            l1->next = dfs(l1->next, l2);//小的节点后面连接小结点之后的链表和另一个链表合并的链表即可
            return l1;
        }
        l2->next = dfs(l1, l2->next);
        return l2;
    }
};

//小总结：
//循环（迭代）和递归都是在解决重复的子问题，那什么时候用递归舒服？什么时候用循环舒服？
//递归vs深搜
//递归的展开图，就是对一棵树进行一次深度优先遍历dfs
//当递归展开图比较复杂，（二叉树，多叉树），用递归比较舒服，用循环的话，得借助栈
//当递归展开图例如单边树，没有分支时，递归就可以比较容易的改成循环