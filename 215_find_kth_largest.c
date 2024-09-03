/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define PEA_STACK_TYPEDEF(__stackTypeName, __cap, __type)                                                           \
    typedef struct __stackTypeName##_tag {                                                                          \
        int cap;                                                                                                    \
        int nr;                                                                                                     \
        __type buf[(__cap)];                                                                                        \
    } __stackTypeName;

#define PEA_STACK_DEF(__stackTypeName, __name)                                                                      \
    __stackTypeName __name = {                                                                                      \
        .cap = sizeof(__name.buf) / sizeof(__name.buf[0]),                                                          \
        .nr = 0,                                                                                                    \
        .buf = {0}};                                                                                                \

#define PEA_STACK_CREATE(__stackTypeName, __cap) ({                                                                 \
    __stackTypeName *__pStack = (__stackTypeName *)malloc(sizeof(*__pStack) + sizeof(*__pStack->buf) * __cap);      \
    if (__pStack == NULL) {                                                                                         \
        printf("Stack malloc failed.");                                                                             \
    } else {                                                                                                        \
        __pStack->cap = (__cap);                                                                                    \
        __pStack->nr = 0;                                                                                           \
    }                                                                                                               \
    __pStack;})

#define PEA_STACK_TOP(__pStack) ({                                                                                  \
    typeof((__pStack)->buf[0]) *__pEle;                                                                             \
    if ((__pStack)->nr == 0) {                                                                                      \
        __pEle = NULL;                                                                                              \
    } else {                                                                                                        \
        __pEle = &(__pStack)->buf[(__pStack)->nr - 1];                                                              \
    }                                                                                                               \
    __pEle;})

#define PEA_STACK_PUSH(__pStack, __ele) ({                                                                          \
    int __rc;                                                                                                       \
    if ((__pStack)->nr == (__pStack)->cap) {                                                                        \
        __rc = -1;                                                                                                  \
    } else {                                                                                                        \
        __rc = 0;                                                                                                   \
        (__pStack)->buf[(__pStack)->nr] = (__ele);                                                                  \
        (__pStack)->nr++;                                                                                           \
    }                                                                                                               \
    __rc;})

#define PEA_STACK_POP(__pStack) ({                                                                                  \
    int __rc;                                                                                                       \
    if ((__pStack)->nr == 0) {                                                                                      \
        __rc = -1;                                                                                                  \
    } else {                                                                                                        \
        __rc = 0;                                                                                                   \
        (__pStack)->nr--;                                                                                           \
    }                                                                                                               \
    __rc;})

int findKthLargestStack(int* nums, int numsSize, int k)
{
    PEA_STACK_TYPEDEF(PeaNumStack_t, 0, int);
    PeaNumStack_t *pStack = PEA_STACK_CREATE(PeaNumStack_t, k);
    PeaNumStack_t *pTmpStack = PEA_STACK_CREATE(PeaNumStack_t, k);

    for (int i = 0; i < numsSize; i++) {
        int tmpNum = nums[i];
        int *pTop;
        pTop = PEA_STACK_TOP(pStack);
        while (pTop != NULL && tmpNum >= *pTop) {
            (void)PEA_STACK_PUSH(pTmpStack, *pTop);
            (void)PEA_STACK_POP(pStack);
            pTop = PEA_STACK_TOP(pStack);
        }
        (void)PEA_STACK_PUSH(pStack, tmpNum);
        pTop = PEA_STACK_TOP(pTmpStack);
        while (pTop != NULL) {
            (void)PEA_STACK_PUSH(pStack, *pTop);
            (void)PEA_STACK_POP(pTmpStack);
            pTop = PEA_STACK_TOP(pTmpStack);
        }
    }
    int res = *PEA_STACK_TOP(pStack);

    return res;
} 

int findKthLargestInsert(int *nums, int numsSize, int k)
{
    int *pKNum = (int *)malloc(sizeof(*pKNum) * k);
    int nr = 0;

    for (int i = 0; i < numsSize; i++) {
        int tmpNum = nums[i];
        if (nr == k && tmpNum < pKNum[nr - 1]) {
            continue;
        }
        int insertPos = 0;
        for (int j = nr - 1; j >= 0; j--) {
            if (j == 0 && tmpNum >= pKNum[j]) {
                insertPos = j;
            } else if (tmpNum < pKNum[j]) {
                insertPos = j + 1;
            } else if (tmpNum >= pKNum[j] && tmpNum < pKNum[j - 1]) {
                insertPos = j;
            } else {
                continue;
            }
            int moveNr = ((nr == k) ? k : (nr + 1)) - insertPos - 1;
            if (moveNr > 0) {
                (void)memmove(&pKNum[insertPos + 1], &pKNum[insertPos], sizeof(*pKNum) * moveNr);
            }
            break;
        }
        pKNum[insertPos] = tmpNum;
        if (nr < k) {
            nr++;
        }
    }
    int res = pKNum[k - 1];
    free(pKNum);
    return res;
}

int findKthLargestBubble(int *nums, int numsSize, int k)
{
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }
    }
    return nums[numsSize - k];
} 

static void peaUtNumSortSwap(void *pArray, int pos1, int pos2)
{
    int tmp = ((int *)pArray)[pos1];
    ((int *)pArray)[pos1] = ((int *)pArray)[pos2];
    ((int *)pArray)[pos2] = tmp;
    return;
}

static void peaQSortK(int *pArray, int left, int right, int tgtPos)
{
    if (left >= right) {
        return;
    }
    int pivatPos = (right + left) / 2;
    int leftPos = left;
    int rightPos = right;

    while (leftPos < rightPos) {
        if (pivatPos < rightPos) { 
            if (pArray[pivatPos] <= pArray[rightPos]) {
                rightPos--;
            } else {
                peaUtNumSortSwap(pArray, pivatPos, rightPos);
                pivatPos = rightPos;
            }
        }
        if (pivatPos > leftPos) {
            if (pArray[pivatPos] >= pArray[leftPos]) {
                leftPos++;
            } else {
                peaUtNumSortSwap(pArray, pivatPos, leftPos);
                pivatPos = leftPos;
            }
        }
    }
    if (pivatPos == tgtPos) {
        return;
    } else if (pivatPos > tgtPos) {
        peaQSortK(pArray, left, pivatPos - 1, tgtPos);
    } else {
        peaQSortK(pArray, pivatPos + 1, right, tgtPos);
    }
    return;
}

int findKthLargestQSort(int *nums, int numsSize, int k)
{
    peaQSortK(nums, 0, numsSize - 1, numsSize - k);
    return nums[numsSize - k];
}

static void peaHeapBuild(int *pArray, int left, int right)
{
    int dadPos = left;
    int sonPos = dadPos * 2 + 1;
    while (sonPos <= right) {
        if (sonPos + 1 <= right && pArray[sonPos] < pArray[sonPos + 1]) {
            sonPos += 1;
        }
        if (pArray[dadPos] < pArray[sonPos]) {
            peaUtNumSortSwap(pArray, dadPos, sonPos);
        } else {
            break;
        }
        dadPos = sonPos;
        sonPos = dadPos * 2 + 1;
    }
    return;
}

int findKthLargest(int *nums, int numsSize, int k)
{
    int right = numsSize - 1;
    int left = 0;
    for (int i = (right + 1) / 2; i >= left; i--) {
        peaHeapBuild(nums, i, right);
    }
    for (int i = right; i >= numsSize - k; i--) {
        peaUtNumSortSwap(nums, 0, i);
        peaHeapBuild(nums, 0, i - 1);
    }
    return nums[numsSize - k];
}

// @lc code=end

