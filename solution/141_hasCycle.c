/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;

    while (pSlow != NULL && pFast != NULL) {
        pSlow = pSlow->next;
        pFast = pFast->next;
        if (pFast != NULL) {
            pFast = pFast->next;
            if (pSlow == pFast) {
                return true;
            }
        }
    }
    return false;
}
// @lc code=end

