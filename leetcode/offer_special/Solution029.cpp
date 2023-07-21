#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

class Solution029
{
public:
    Node *insert(Node *head, int insertVal)
    {
        Node *insertNode = new Node(insertVal);
        // 循环链表中有空结点
        if (head == nullptr)
        {
            insertNode->next = insertNode;
            return insertNode;
        }
        // 循环链表中有1个结点
        if (head->next == nullptr)
        {
            head->next = insertNode;
            insertNode->next = head;
            return head;
        }
        // 循环链表中有多个结点
        Node *p = head, *pNext = p->next;
        // pNext非尾结点
        /**
         * pNext, head尾头结点
         * - p->val <= pNext->val
         * -- 7->9，8，7->8->9
         * -- 7->7，7，7->7->7
         * -- 7->9，7，7->7->9
         * -- 7->9，9，7->9->9
         * - p->val > pNext->val
         * -- 8->2，9，8->9->2
         * -- 8->2，1，8->1->2
         */
        while (pNext != head)
        {
            if (p->val <= pNext->val)
            {
                if (p->val <= insertVal && insertVal <= pNext->val)
                {
                    p->next = insertNode;
                    insertNode->next = pNext;
                    return head;
                }
            }
            else
            {
                if (p->val < insertVal && insertVal > pNext->val)
                {
                    p->next = insertNode;
                    insertNode->next = pNext;
                    return head;
                }
                if (p->val > insertVal && insertVal < pNext->val)
                {
                    p->next = insertNode;
                    insertNode->next = pNext;
                    return head;
                }
            }
            p = pNext;
            pNext = pNext->next;
        }
        p->next = insertNode;
        insertNode->next = pNext;
        return head;
    }
};