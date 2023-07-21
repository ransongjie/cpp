#ifndef _Node_H_
#define _Node_H_
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node *child;
    Node(int val);
};
#endif