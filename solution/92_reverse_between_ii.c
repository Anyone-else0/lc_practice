/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "stddef.h"
#include "92_reverse_between_ii.h"

typedef struct ListNode ListNode_t;

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    ListNode_t *pPreLeft = NULL;

    ListNode_t *pNode = head;

    ListNode_t *pNewHead;
    ListNode_t *pTmpHead;
    ListNode_t *pNewLast;

    for (int pos = 1; pos <= right; pos++) {
        if (pos == left - 1) {
            pPreLeft = pNode;
        }
        if (pos >= left) {
            if (pos == left) {
                pNewHead = pNode;
                pTmpHead = pNewHead;
                pNewLast = pNode;
                pNode = pNode->next;
            } else {
                pNewHead = pNode;
                pNode = pNode->next;
                pNewHead->next = pTmpHead;
                pTmpHead = pNewHead;
            }
        } else {
            pNode = pNode->next;
        }
    }

    ListNode_t *pRes;

    if (pPreLeft == NULL) {
        pRes = pNewHead;
    } else {
        pRes = head;
        pPreLeft->next = pNewHead;
    }
    pNewLast->next = pNode;
    return pRes;
}
// @lc code=end

