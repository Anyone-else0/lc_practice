/*
 * @lc app=leetcode.cn id=147 lang=c
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head)
{
    struct ListNode *pRes = NULL;
    struct ListNode *pNode = head;
    while (pNode != NULL) {
        struct ListNode *pNext = pNode->next;
        pNode->next = NULL;
        struct ListNode *pCur = pRes;
        struct ListNode *pPre = pRes;
        while (pCur != NULL) {
            if (pCur->val < pNode->val) {
                pPre = pCur;
                pCur = pCur->next;
            } else {
                break;
            }
        }
        if (pCur == pPre) {
            pNode->next = pRes;
            pRes = pNode;
        } else {
            pPre->next = pNode;
            pNode->next = pCur;
        }
        pNode = pNext;
    }

    return pRes;
}
// @lc code=end

