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
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *stack = (int *)malloc(sizeof(int) * numsSize * 2);
    if (stack == NULL) {
        *returnSize = 0;
        free(res);
        return NULL;
    }
    *returnSize = numsSize;
    int stackTop = 0;
    stack[stackTop] = 0;
    int currentNumsIndex = 1;
    while (stackTop >= 0) {
        if (currentNumsIndex >= (2 * numsSize - 1)) {
            while (stackTop >= 0) {
                if (stack[stackTop] < numsSize) {
                    res[stack[stackTop]] = -1;
                }
                stackTop--;
            }
        } else {
            while (stackTop >= 0 && nums[currentNumsIndex % numsSize] > nums[stack[stackTop] % numsSize]) {
                if (stack[stackTop] < numsSize) {
                    res[stack[stackTop]] = nums[currentNumsIndex % numsSize];
                }
                stackTop--;
            }
            stackTop++;
            stack[stackTop] = currentNumsIndex;
        }
        currentNumsIndex++;
    }
    free(stack);
    return res;
}
// @lc code=end
