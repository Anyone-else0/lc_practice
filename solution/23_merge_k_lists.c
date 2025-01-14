/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "23_merge_k_lists.h"
#include <stddef.h>

typedef struct ListNode ListNode_t;

static void heapSort(struct ListNode** lists, int left, int right)
{
    int dadPos = left;
    int sonPos = dadPos * 2 + 1;
    while (sonPos <= right) {
        if (sonPos + 1 <= right && 
            (lists[sonPos] == NULL || (lists[sonPos + 1] != NULL && lists[sonPos]->val > lists[sonPos + 1]->val))) {
            sonPos++;
        }

        if (lists[dadPos] == NULL || (lists[sonPos] != NULL && lists[dadPos]->val > lists[sonPos]->val)) {
            ListNode_t *pTmp = lists[dadPos];
            lists[dadPos] = lists[sonPos];
            lists[sonPos] = pTmp;
        } else {
            break;
        }
        dadPos = sonPos;
        sonPos = dadPos * 2 + 1;
    }
    return;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    ListNode_t *pRes = NULL;
    ListNode_t *pTmp = NULL;
    int left = 0;
    int right = listsSize - 1;
    if (lists == NULL || listsSize <= 0) {
        return pRes;
    }
    for (int i = (right + 1) / 2; i >= left; i--) {
        heapSort(lists, i, right);
    }
    if (lists[0] == NULL) {
        return pRes;
    }
    ListNode_t *pCur;
    while (right >= 0) {
        pCur = lists[0];
        if (lists[0] != NULL) {
            lists[0] = lists[0]->next;
        } else {
            lists[0] = lists[right];
            right--;
        }

        if (pRes == NULL) {
            pRes = pCur;
            pTmp = pCur;
        } else if (pTmp != NULL) {
            pTmp->next = pCur;
            pTmp = pTmp->next;
        }

        heapSort(lists, left, right);
    }

    return pRes;
}
// @lc code=end

