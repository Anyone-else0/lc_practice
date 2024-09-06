/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_hash_table.h"

#define MAX_IDX (1000)
typedef struct HashKey {
    int num;
} HashKey_t;

typedef struct HashValue {
    int idx;
} HashValue_t;

int *twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    PeaHashTable_t *pTable = peaHashTableCreate(100);
    PeaHashKv_t *pTmpKv = (PeaHashKv_t *)malloc(sizeof(*pTmpKv) + sizeof(HashKey_t) + sizeof(HashValue_t)
        + sizeof(int) * 1);
    pTmpKv->keyLen = sizeof(HashKey_t);
    pTmpKv->pKey = &pTmpKv->pad[0];
    pTmpKv->valueLen = sizeof(HashValue_t);
    pTmpKv->pValue = &pTmpKv->pad[pTmpKv->keyLen];
    HashKey_t *pTmpKey = pTmpKv->pKey;
    HashValue_t *pTmpValue = pTmpKv->pValue;
    *returnSize = 0;
    int *pRes = (int *)malloc(sizeof(*pRes) * 2);

    for (int i = 0; i < numsSize; i++) {
        int num1 = nums[i];
        int idx1 = i;
        pTmpKey->num = target - num1;
        int rc = peaHashTableKvPick(pTable, pTmpKv);
        if (rc == 0) {
            pRes[0] = pTmpValue->idx;
            pRes[1] = idx1;
            *returnSize = 2;
            goto l_end;
        }

        pTmpKey->num = num1;
        rc = peaHashTableKvGet(pTable, pTmpKv);
        if (rc != 0) {
            pTmpValue->idx = i;
            (void)peaHashTableKvPut(pTable, pTmpKv);
        }
    }

l_end:
    free(pTmpKv);
    peaHashTableDestroy(pTable);
    return pRes;
}
// @lc code=end
