/*
 * @lc app=leetcode.cn id=817 lang=c
 *
 * [817] 链表组件
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "stddef.h"
#include "817_num_components.h"

#define MAX_NUMS (10000)
#define MAX_NUMS_BITMAP_SIZE (MAX_NUMS / 32 + 1)

typedef struct ListNode ListNode_t;

int numComponents(struct ListNode* head, int* nums, int numsSize)
{
    unsigned int numsBitmap[MAX_NUMS_BITMAP_SIZE] = {0};
    for (int i = 0; i < numsSize; i++) {
        numsBitmap[nums[i] / 32] |= 1u << ((unsigned int)nums[i] % 32);
    }
    ListNode_t *pTmp = head;
    int count = 0;

    while (pTmp != NULL) {
        if (numsBitmap[pTmp->val / 32] & (1u << ((unsigned int)pTmp->val % 32))) {
            count++;
            while (pTmp != NULL && (numsBitmap[pTmp->val / 32] & (1u << ((unsigned int)pTmp->val % 32)))) {
                pTmp = pTmp->next;
            }
        } else {
            pTmp = pTmp->next;
        }
    }

    return count;
}
// @lc code=end

