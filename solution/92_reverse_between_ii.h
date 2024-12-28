#ifndef __92_REVERSE_BETWEEN_II_H__
#define __92_REVERSE_BETWEEN_II_H__

typedef struct ListNode
{
    int val;
    struct ListNode *next;
}ListNode_t;

struct ListNode *reverseBetween(struct ListNode* head, int left, int right);

#endif