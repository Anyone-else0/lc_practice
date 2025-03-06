/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head)
{
    struct ListNode *pEven = NULL;
    struct ListNode *pEvenTail = NULL;
    struct ListNode *pOdd = NULL;
    struct ListNode *pOddTail = NULL;
    struct ListNode *pNode = head;
    struct ListNode *pTail = NULL;

    while (pNode != NULL) {
        struct ListNode *pNext = pNode->next;
        pNode->next = NULL;
        if (pTail == NULL) {
            if (pEven == NULL) {
                pEven = pNode;
                pEvenTail = pNode;
                pTail = pOddTail;
            } else {
                pOdd = pNode;
                pOddTail = pNode;
                pTail = pEvenTail;
            }
        } else {
            pTail->next = pNode;
            if (pTail == pEvenTail) {
                pEvenTail = pEvenTail->next;
                pTail = pOddTail;
            } else {
                pOddTail = pOddTail->next;
                pTail = pEvenTail;
            }
        }

        pNode = pNext;
    }

    if (pEvenTail != NULL) {
        pEvenTail->next = pOdd;
    }

    return pEven;
}
// @lc code=end

