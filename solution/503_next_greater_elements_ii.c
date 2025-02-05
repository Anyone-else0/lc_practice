/*
 * @lc app=leetcode.cn id=503 lang=c
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "pea_stack.h"

int *nextGreaterElements(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * numsSize);
    (void)memset(res, -1, sizeof(int) * numsSize);
    PeaStack_t *pStack = peaStackCreate(numsSize, sizeof(int));
    for (int i = 0; i < 2 * numsSize - 1; i++) {
        int realIdx = i % numsSize;
        int *pTop = (int *)pStack->pfTop(pStack);
        while (pTop != NULL && nums[realIdx] > nums[*pTop]) {
            res[*pTop] = nums[realIdx];
            pStack->pfPop(pStack);
            pTop = (int *)pStack->pfTop(pStack);
        }
        pStack->pfPush(pStack, &realIdx);
    }
    pStack->pfDestroy(pStack);
    *returnSize = numsSize;
    return res;
}
// @lc code=end
