#define _CRT_SECURE_NO_WARNINGS

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

//k个一组翻转链表
//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
//
//示例 1：
//
//输入：head = [1, 2, 3, 4, 5], k = 2
//输出：[2, 1, 4, 3, 5]
//
//示例 2：
//
//输入：head = [1, 2, 3, 4, 5], k = 3
//输出：[3, 2, 1, 4, 5]

//先计算要翻转多少组，即链表长度/k
//然后两层循环n组，每组k个结点进行翻转
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int n = 0;

        while (cur)
        {
            n++;
            cur = cur->next;
        }

        n /= k;

        ListNode* newhead = new ListNode(0);
        ListNode* prev = newhead;
        cur = head;

        for (int i = 0; i < n; i++)
        {
            //每完成一组翻转之前，要事先记录每次翻转的首位置，因为首位置翻转后到该组的最后，正好成为下一组的“虚拟头结点”
            ListNode* tmp = cur;
            for (int j = 0; j < k; j++)
            {
                ListNode* next = cur->next;//记录cur->next，以防头插时丢失
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
            prev = tmp;//将原先虚拟头结点的位置更新
        }
        //最后将不需要翻转的结点直接链入链表末尾即可
        prev->next = cur;

        cur = newhead->next;
        delete newhead;
        return cur;
    }
};