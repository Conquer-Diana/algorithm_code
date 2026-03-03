#define _CRT_SECURE_NO_WARNINGS

#include <queue>

using namespace std;

//合并K个升序链表
//给你一个链表数组，每个链表都已经按升序排列。
//
//请你将所有链表合并到一个升序链表中，返回合并后的链表。
//
//示例 1：
//
//输入：lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
//输出：[1, 1, 2, 3, 4, 4, 5, 6]
//解释：链表数组如下：
//[
//	1->4->5,
//	1->3->4,
//	2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6

//方法1：借助优先级队列（小根堆版）进行优化
struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_1 {
    struct greater
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, greater> pq;
        ListNode* newhead = new ListNode(0);
        ListNode* newtail = newhead;

        //先将每个链表的头结点都入队列
        for (auto& node : lists)
            if (node)
                pq.push(node);

        //在队列不为空时，取堆顶元素并弹出，尾插到虚拟头结点后，再看堆顶元素的next为不为空，不为空入堆
        while (!pq.empty())
        {
            ListNode* newnode = pq.top();
            pq.pop();
            newtail->next = newnode;
            newtail = newnode;
            if (newnode->next)
                pq.push(newnode->next);
        }

        newtail = newhead->next;
        delete newhead;
        return newtail;
    }
};

//方法2：分治递归，同归并排序一样，先分后合，分是递归，合是合并两个有序链表
class Solution_2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, lists.size() - 1);
    }

    //合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* newhead = new ListNode(0);
        ListNode* tail = newhead, * cur1 = l1, * cur2 = l2;

        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                tail->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                tail->next = cur2;
                cur2 = cur2->next;
            }
            tail = tail->next;
        }
        if (cur1)
            tail->next = cur1;
        if (cur2)
            tail->next = cur2;

        tail = newhead->next;
        delete newhead;

        return tail;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r)
    {
        if (l > r)///没有链表
            return nullptr;
        if (l == r)//只有一个链表
            return lists[l];

        int mid = l + (r - l) / 2;

        ListNode* left = mergeSort(lists, l, mid);
        ListNode* right = mergeSort(lists, mid + 1, r);

        return mergeTwoLists(left, right);
    }
};



