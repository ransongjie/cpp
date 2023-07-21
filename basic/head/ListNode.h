#ifndef _ListNode_H_
#define _ListNode_H_
//防止被多次插入到.cpp文件中

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode(int val);

    ListNode(int val, ListNode *next);
};

#endif