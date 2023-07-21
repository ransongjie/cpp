#include <iostream>
#include "ListNode.h"
using namespace std;
/**
 * 删除链表的倒数第 n 个结点
 */
class Solution021
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0, head);
        ListNode *pi = &dummy, *pj = head; // pi指向倒数第n+1个结点
        int i = 0;
        for (; i < n; i++)
        {
            pj = pj->next;
        }
        while (pj != NULL)
        {
            pj = pj->next;
            pi = pi->next;
        }
        pi->next = pi->next->next;
        return dummy.next;
    }
};