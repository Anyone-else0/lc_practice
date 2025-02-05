/*
 * @lc app=leetcode.cn id=215 lang=c
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include "pea_stack.h"

int findKthLargestStack(int* nums, int numsSize, int k)
{
    PeaStack_t *pStack = peaStackCreate(k, sizeof(nums[0]));
    PeaStack_t *pTmpStack = peaStackCreate(k, sizeof(nums[0]));

    for (int i = 0; i < numsSize; i++) {
        int tmpNum = nums[i];
        int *pTop;
        pTop = (int *)pStack->pfTop(pStack);
        while (pTop != NULL && tmpNum >= *pTop) {
            (void)pTmpStack->pfPush(pTmpStack, pTop);
            (void)pStack->pfPop(pStack);
            pTop = (int *)pStack->pfTop(pStack);
        }
        (void)pStack->pfPush(pStack, &tmpNum);
        pTop = (int *)pTmpStack->pfTop(pTmpStack);
        while (pTop != NULL) {
            (void)pStack->pfPush(pStack, pTop);
            (void)pTmpStack->pfPop(pTmpStack);
            pTop = (int *)pTmpStack->pfTop(pTmpStack);
        }
    }
    int res = *((int *)pStack->pfTop(pStack));
    pStack->pfDestroy(pStack);
    pTmpStack->pfDestroy(pTmpStack);

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

