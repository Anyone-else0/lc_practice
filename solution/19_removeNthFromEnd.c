/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *pFast = head;
    struct ListNode *pSlow = head;
    struct ListNode *pSlowPre = head;

    int i = 1;
    while (pFast->next != NULL) {
        pFast = pFast->next;
        if (i < n) {
            i++;
        } else {
            pSlowPre = pSlow;
            pSlow = pSlow->next;
        }
    }

    if (pSlow == head) {
        return pSlow->next;
    } else {
        pSlowPre->next = pSlow->next;
        return head;
    }
}
// @lc code=end

