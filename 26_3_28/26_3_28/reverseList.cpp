#define _CRT_SECURE_NO_WARNINGS


//反转链表（递归版）
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//将问题倒过来看，从第一个节点开始，先将后面的链表逆置，重复子问题就是先将后面逆置，然后将该节点的下一个节点的next指向该节点，该节点指向空
//可以宏观来看递归，也可以把链表当成一棵单边树，进行一次dfs（后序遍历），代码是一样的
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)//递归出口：当结点只有一个或者直接为空时返回
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};