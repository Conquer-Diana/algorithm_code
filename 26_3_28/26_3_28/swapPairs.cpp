#define _CRT_SECURE_NO_WARNINGS

//两两交换链表中的结点（递归版）
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

//重复子问题：先将该节点的后两个结点之后的链表两两交换好，然后用tmp记录交换后链表的头，随后将该节点的下一个结点的next指向该节点，该节点的next指向tmp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* tmp = swapPairs(head->next->next);
        ListNode* ret = head->next;
        head->next->next = head;
        head->next = tmp;

        return ret;
    }
};