/*
 * @lc app=leetcode.cn id=445 lang=c
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "pea_stack.h"
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *pRes = NULL;
    PeaStack_t *pL1Stack = peaStackCreate(100, sizeof(int));
    PeaStack_t *pL2Stack = peaStackCreate(100, sizeof(int));
    struct ListNode *pNode = l1;
    while (pNode) {
        pL1Stack->pfPush(pL1Stack, &pNode->val);
        pNode = pNode->next;
    }
    pNode = l2;
    while (pNode) {
        pL2Stack->pfPush(pL2Stack, &pNode->val);
        pNode = pNode->next;
    }
    int a;
    int b;
    int c = 0;
    int s;
    while (pL1Stack->pfEmpty(pL1Stack) == false || pL2Stack->pfEmpty(pL2Stack) == false) {
        if (pL1Stack->pfEmpty(pL1Stack) == false) {
            a = *(int *)pL1Stack->pfTop(pL1Stack);
            pL1Stack->pfPop(pL1Stack);
        } else {
            a = 0;
        }
        if (pL2Stack->pfEmpty(pL2Stack) == false) {
            b = *(int *)pL2Stack->pfTop(pL2Stack);
            pL2Stack->pfPop(pL2Stack);
        } else {
            b = 0;
        }
        s = a + b + c;
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->val = s % 10;
        pNode->next = pRes;
        pRes = pNode;
        c = s / 10;
    }

    if (c != 0) {
        pNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        pNode->val = c;
        pNode->next = pRes;
        pRes = pNode;
    }
    pL1Stack->pfDestroy(pL1Stack);
    pL2Stack->pfDestroy(pL2Stack);
    return pRes;
}
// @lc code=end

