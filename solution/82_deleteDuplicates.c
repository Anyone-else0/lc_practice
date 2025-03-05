/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *pRes = head;
    if (head == NULL || head->next == NULL) {
        goto l_end;
    }

    struct ListNode *pPrev = NULL;
    struct ListNode *pCur = head;
    struct ListNode *pNext = head->next;

    while (pNext != NULL) {
        while (pNext != NULL && pCur->val == pNext->val) {
            pNext = pNext->next;
        }
        if (pCur->next != pNext) {
            if (pPrev == NULL) {
                pRes = pNext;
                pCur = pNext;
                if (pNext != NULL) {
                    pNext = pNext->next;
                }
            } else {
                pPrev->next = pNext;
                pCur = pNext;
                if (pNext != NULL) {
                    pNext = pNext->next;
                }
            }
        } else {
            pPrev = pCur;
            pCur = pNext;
            pNext = pCur->next;
        }
    }

l_end:
    return pRes;
}
// @lc code=end

