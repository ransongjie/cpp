#include "ListNode.h"

ListNode::ListNode(int val) {
    this->val = val;
}

ListNode::ListNode(int val, ListNode *next) {
    this->val = val;
    this->next = next;
}
