/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode list1 = { 0 };
    struct ListNode list2 = { 0 };
    struct ListNode *p1 = &list1;
    struct ListNode *p2 = &list2;
    struct ListNode *pTmp = head;

    while (pTmp != NULL) {
        if (pTmp->val < x) {
            p1->next = pTmp;
            p1 = p1->next;
        } else {
            p2->next = pTmp;
            p2 = p2->next;
        }
        pTmp = pTmp->next;
    }

    p1->next = NULL;
    p2->next = NULL;

    struct ListNode *pRes = list1.next;
    if (pRes != NULL) {
        p1->next = list2.next;
    } else {
        pRes = list2.next;
    }

    return pRes;
}
// @lc code=end

