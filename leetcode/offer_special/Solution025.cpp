#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution025
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // 反转链表
        ListNode *n1 = reverse(l1);
        ListNode *n2 = reverse(l2);
        // 商，余数
        int q = 0, r = 0, a = 0, b = 0;
        ListNode *head = NULL, *p = NULL;
        // 头插法
        while (n1 != NULL || n2 != NULL || q != 0)
        {
            a = n1 == NULL ? 0 : n1->val;
            b = n2 == NULL ? 0 : n2->val;
            r = a + b + q;
            q = r / 10;
            r = r % 10;
            p = new ListNode(r, head);
            head = p;
            //
            n1 = n1 == NULL ? n1 : n1->next;
            n2 = n2 == NULL ? n2 : n2->next;
        }
        return head;
    }

private:
    ListNode *reverse(ListNode *node)
    {
        if (node == NULL || node->next == NULL)
        {
            return node;
        }
        ListNode *newHead = reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return newHead;
    }
};