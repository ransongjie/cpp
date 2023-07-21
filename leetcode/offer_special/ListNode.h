#ifndef _ListNode_H_
#define _ListNode_H_

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val);
    ListNode(int val, ListNode *next);
};

#endif