#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

class Solution028
{
public:
    Node *flatten(Node *head)
    {
        dfs(head);
        return head;
    }

private:
    Node *dfs(Node *p)
    {
        Node *l = nullptr, *tmp = nullptr;
        while (p != nullptr)
        {
            if (p->child != nullptr)
            {
                l = dfs(p->child);
                if (p->next == nullptr)
                {
                    p->next = p->child;
                    p->child->prev = p;
                    p->child = nullptr;
                }
                else
                {
                    tmp = p->next;
                    p->next = p->child;
                    p->child->prev = p;
                    p->child = nullptr;
                    l->next = tmp;
                    tmp->prev = l;
                }
            }
            else
            {
                l = p;
            }
            p = p->next;
        }
        return l;
    }
};