/*
 * @lc app=leetcode.cn id=47 lang=c
 *
 * [47] 全排列 II
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include "stddef.h"
#include "stdlib.h"
#include "string.h"

typedef struct PermuteInfo
{
    int *nums;
    int numsSize;
    int **res;
    int resNr;
} PermuteInfo_t;

int factorial(int a)
{
    int res = 1;
    for (int i = 1; i <= a; i++) {
        res *= i;
    }
    return res;
}

void dfsPermute(PermuteInfo_t *pInfo, int *pRec, unsigned int usedBm, int depth, int *pSeq)
{
    if (depth == pInfo->numsSize) {
        pInfo->res[pInfo->resNr] = (int *)malloc(sizeof(int) * pInfo->numsSize);
        memcpy(pInfo->res[pInfo->resNr], pSeq, sizeof(int) * pInfo->numsSize);
        pInfo->resNr++;
        return;
    }

    for (int i = 0; i < pInfo->numsSize; i++) {
        if ((usedBm & (1 << i)) != 0) {
            continue;
        }
        if (pRec[pInfo->nums[i] + 10] != -1 && pRec[pInfo->nums[i] + 10] > i) {
            continue;
        }
        int oriRec = pRec[pInfo->nums[i] + 10];
        pSeq[depth] = pInfo->nums[i];
        pRec[pInfo->nums[i] + 10] = i;
        usedBm |= (1 << i);
        dfsPermute(pInfo, pRec, usedBm, depth + 1, pSeq);
        pRec[pInfo->nums[i] + 10] = oriRec;
        usedBm &= ~(1 << i);
    }

    return;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int maxSize = factorial(numsSize);
    *returnColumnSizes = (int *)malloc(maxSize * sizeof(int));
    for (int i = 0; i < maxSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }

    int **res = (int **)malloc(maxSize * sizeof(int *));
    int rec[21];
    unsigned int usedBm = 0;

    PermuteInfo_t info = {
        .nums = nums,
        .numsSize = numsSize,
        .res = res,
        .resNr = 0,
    };

    int *pSeq = (int *)malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        memset(rec, -1, sizeof(rec));
        memset(pSeq, -1, sizeof(int) * numsSize);
        pSeq[0] = nums[i];
        rec[nums[i] + 10] = i;
        usedBm = 0;
        usedBm |= (1 << i);
        dfsPermute(&info, rec, usedBm, 1, pSeq);
    }

    *returnSize = info.resNr;
    return res;
}
// @lc code=end

