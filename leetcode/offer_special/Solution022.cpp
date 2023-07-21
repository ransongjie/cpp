#include <iostream>
#include <unordered_set>
#include "ListNode.h"
using namespace std;

class Solution022
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> visited;
        ListNode *p = head;
        while (p != NULL)
        {
            if (visited.count(p))
            {
                return p;
            }
            else
            {
                visited.insert(p); //
            }
            p = p->next;
        }
        return NULL;
    }
};