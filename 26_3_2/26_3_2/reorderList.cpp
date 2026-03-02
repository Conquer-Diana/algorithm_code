#define _CRT_SECURE_NO_WARNINGS

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//重排链表
//给定一个单链表 L 的头节点 head ，单链表 L 表示为：
//
//L0 → L1 → … → Ln - 1 → Ln
//请将其重新排列后变为：
//
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//
//不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

//本题是求链表的中间结点+反转链表+合并链表的缝合怪
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head, * slow = head;

        //求中间结点
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //引入虚拟头结点，将中间结点slow后面的结点重新组成一个链表
        //并将slow与后面断开
        ListNode* head2 = new ListNode(0);
        ListNode* cur = slow->next;
        slow->next = nullptr;

        //头插法反转链表
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = next;
        }

        //尾插合并链表
        ListNode* ret = new ListNode(0);
        ListNode* tail = ret;
        ListNode* cur1 = head;
        ListNode* cur2 = head2->next;

        while (cur1)//无论如何 都是第一个链表比较长
        {
            //先插入第一个链表
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;

            //在插入第二个链表
            if (cur2)
            {
                tail->next = cur2;
                tail = tail->next;
                cur2 = cur2->next;
            }
        }
        delete head2;
        head = ret->next;
        delete ret;
    }
};