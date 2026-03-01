#define _CRT_SECURE_NO_WARNINGS

//两两交换链表中的节点
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//
//示例 1：
//输入：head = [1, 2, 3, 4]
//输出：[2, 1, 4, 3]

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

//重点画图理解
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* newhead = new ListNode(0, head);
        ListNode* prev = newhead;
        ListNode* cur = prev->next;
        ListNode* next = cur->next;
        //cur和next需要判空，以免引起空指针错误，其对应链表为空和链表只有一个元素的情况
        ListNode* nnext = next->next;
        while (cur && next)
        {
            prev->next = next;
            next->next = cur;
            cur->next = nnext;

            prev = cur;
            cur = prev->next;
            //下面也是一样，cur和next一旦为空，则不往下走
            if (!cur)
                break;
            next = cur->next;
            if (!next)
                break;
            nnext = next->next;
        }

        prev = newhead->next;
        delete newhead;
        return prev;

    }
};