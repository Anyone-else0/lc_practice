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
#include <stddef.h>

struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    struct ListNode *pPreLeft = NULL;

    struct ListNode *pNode = head;

    struct ListNode *pNewHead;
    struct ListNode *pTmpHead;
    struct ListNode *pNewLast;

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

    struct ListNode *pRes;

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

