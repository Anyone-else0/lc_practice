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
/*
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
*/
#include "pea_stack.h"
typedef struct StackNode {
    int val;
    int idx;
} StackNode_t;
int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
    if (head == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *pRes = (int *)malloc(sizeof(int) * 10000);
    PeaStack_t *pStack = peaStackCreate(10000, sizeof(StackNode_t));
    struct ListNode *pNode = head;
    int idx = 0;
    while (pNode != NULL) {
        if (pStack->pfEmpty(pStack)) {
            StackNode_t node = {pNode->val, idx};
            pStack->pfPush(pStack, &node);
        } else {
            StackNode_t *pTop = (StackNode_t *)pStack->pfTop(pStack);
            while (pTop->val < pNode->val) {
                pRes[pTop->idx] = pNode->val;
                pStack->pfPop(pStack);
                if (pStack->pfEmpty(pStack)) {
                    break;
                }
                pTop = (StackNode_t *)pStack->pfTop(pStack);
            }
            StackNode_t node = {pNode->val, idx};
            pStack->pfPush(pStack, &node);
        }
        idx++;
        pNode = pNode->next;
    }
    while (!pStack->pfEmpty(pStack)) {
        StackNode_t *pTop = (StackNode_t *)pStack->pfTop(pStack);
        pRes[pTop->idx] = 0;
        pStack->pfPop(pStack);
    }
    pStack->pfDestroy(pStack);
    *returnSize = idx;
    return pRes;
}
// @lc code=end

