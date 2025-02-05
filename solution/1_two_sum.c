/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "pea_hash_table.h"

#define MAX_IDX (1000)

typedef struct HashKv {
    int num;
    int idx;
} HashKv_t;

static int hashKeyCmp(void *pKey1, void *pKey2)
{
    return *(int *)pKey1 - *(int *)pKey2;
}

static int hashGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

static void *hashGetKey(void *pKv)
{
    return (void *)(&(((HashKv_t *)pKv)->num));
}

int *twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    PeaHashTable_t *pTable = peaHashTableCreate(100, hashKeyCmp, hashGetIdx, hashGetKey);
    *returnSize = 0;
    int *pRes = (int *)malloc(sizeof(*pRes) * 2);

    for (int i = 0; i < numsSize; i++) {
        int num1 = nums[i];
        int idx1 = i;
        int num2 = target - num1;
        HashKv_t *pKv = pTable->pfKvPick(pTable, &num2);
        if (pKv != NULL) {
            pRes[0] = pKv->idx;
            pRes[1] = idx1;
            *returnSize = 2;
            goto l_end;
        }

        pKv = pTable->pfKvGet(pTable, &num1);
        if (pKv == NULL) {
            pKv = (HashKv_t *)malloc(sizeof(*pKv));
            pKv->num = num1;
            pKv->idx = idx1;
            (void)pTable->pfKvPut(pTable, pKv);
        }
    }

l_end:
    pTable->pfDestroy(pTable);
    return pRes;
}
// @lc code=end
