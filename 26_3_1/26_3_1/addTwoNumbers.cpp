#define _CRT_SECURE_NO_WARNINGS

//两数相加
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

//示例 1：
//
//输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
//输出：[7, 0, 8]
//解释：342 + 465 = 807.
//
//示例 2：
//
//输入：l1 = [0], l2 = [0]
//输出：[0]
//
//示例 3：
//
//输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//输出：[8, 9, 9, 9, 0, 0, 0, 1]

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

//相加计算后，记录进位
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode(0);
        ListNode* newtail = newhead;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        int t = 0;

        while (cur1 || cur2)
        {
            if (cur1 && cur2)
                t += cur1->val + cur2->val;
            if (!cur1)
                t += cur2->val;
            if (!cur2)
                t += cur1->val;

            ListNode* newnode = new ListNode(t % 10);
            newtail->next = newnode;
            newtail = newnode;

            t /= 10;

            if (cur1)
                cur1 = cur1->next;
            if (cur2)
                cur2 = cur2->next;
        }
        if (t)
        {
            ListNode* newnode = new ListNode(t);
            newtail->next = newnode;
            newtail = newnode;
        }

        newtail = newhead->next;
        delete newhead;

        return newtail;
    }
};