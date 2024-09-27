/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */
// @lc code=start
#include <stdlib.h>
#include "pea_hash_table.h"

typedef struct MajorityElementEntry {
    int num;
    int count;
} MajorityElementEntry_t;

static int majorityElementKeyCmp(void *key1, void *key2)
{
    return *(int *)key1 - *(int *)key2;
}

static int majorityElementGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

static void *majorityElementGetKey(void *pKv)
{
    return (void *)(&((MajorityElementEntry_t *)pKv)->num);
}

int majorityElementHash(int* nums, int numsSize)
{
    int res = nums[0];
    PeaHashTable_t *pTable = peaHashTableCreate(numsSize,
        majorityElementKeyCmp, majorityElementGetIdx, majorityElementGetKey);
    for (int i = 0; i < numsSize; i++) {
        MajorityElementEntry_t *pEntry = pTable->pfKvGet(pTable, &nums[i]);
        if (pEntry == NULL) {
            pEntry = (MajorityElementEntry_t *)malloc(sizeof(*pEntry));
            pEntry->num = nums[i];
            pEntry->count = 1;
            pTable->pfKvPut(pTable, pEntry);
        } else {
            if (pEntry->count == numsSize / 2) {
                res = pEntry->num;
                goto l_end;
            }
            pEntry->count++;
        }
    }

l_end:
    pTable->pfDestroy(pTable);
    return res;
}

int majorityElement(int* nums, int numsSize)
{
    int curNum;
    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (cnt == 0) {
            curNum = nums[i];
            cnt = 1;
        } else if (nums[i] == curNum) {
            cnt++;
        } else {
            cnt--;
        }
    }

    return curNum;
}

// @lc code=end

