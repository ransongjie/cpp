#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution026
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *p = head;
        vector<ListNode *> vec;
        while (p != nullptr)
        {
            vec.emplace_back(p); //
            p = p->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j)
        {
            vec[i]->next = vec[j];
            vec[j]->next = nullptr;
            i++;
            if (i == j)
            {
                break;
            }
            vec[j]->next = vec[i];
            vec[i]->next = nullptr;
            j--;
        }
    }
};