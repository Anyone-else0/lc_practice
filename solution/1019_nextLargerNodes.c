/*
 * @lc app=leetcode.cn id=1019 lang=c
 *
 * [1019] 链表中的下一个更大节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 8 7 6 8 9

int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
    if (head == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *pRes = (int *)malloc(sizeof(int) * 10000);
    int resNr = 0;
    struct ListNode *pSlow = head;
    struct ListNode *pFast = head;
    int slowIdx = 0;
    int fastIdx = 0;
    while (pSlow) {
        pFast = pSlow->next;
        fastIdx = slowIdx + 1;
        while (pFast) {
            if (pFast->val > pSlow->val) {
                pRes[resNr++] = pFast->val;
                break;
            }
            pFast = pFast->next;
            fastIdx++;
        }
        if (pFast == NULL) {
            pRes[resNr++] = 0;
        }
        pSlow = pSlow->next;
        slowIdx++;
    }
    *returnSize = resNr;
    return pRes;
}
// @lc code=end

