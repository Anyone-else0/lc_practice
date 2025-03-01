/*
 * @lc app=leetcode.cn id=143 lang=c
 *
 * [143] 重排链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL) {
        goto l_end;
    }

    struct ListNode *pFast = head;
    struct ListNode *pSlow = head;

    while (pFast != NULL && pFast->next != NULL) {
        pSlow = pSlow->next;
        pFast = pFast->next;
        pFast = pFast->next;
    }

    pFast = pSlow->next;
    pSlow->next = NULL;

    struct ListNode *pTmp = pFast;
    pFast = NULL;
    while (pTmp != NULL) {
        struct ListNode *pNext = pTmp->next;
        pTmp->next = pFast;
        pFast = pTmp;
        pTmp = pNext;
    }

    pSlow = head->next;
    pTmp = head;
    while (pSlow != NULL || pFast != NULL) {
        if (pFast != NULL) {
            pTmp->next = pFast;
            pTmp = pTmp->next;
            pFast = pFast->next;
        }
        if (pSlow != NULL) {
            pTmp->next = pSlow;
            pTmp = pTmp->next;
            pSlow = pSlow->next;
        }
    }

l_end:
    return;
}
// @lc code=end

