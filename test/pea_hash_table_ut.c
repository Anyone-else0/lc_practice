#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pea_hash_table_ut.h"
#include "pea_hash_table.h"

#define PEA_HASH_BUCKET_CAP (10)

typedef struct PeaUtHashKv {
    int key;
    int val;
} PeaUtHashKv_t;

static int peaHashUtKeyCmp(void *key1, void *key2)
{
    return *(int *)key1 - *(int *)key2;
}

static int peaHashUtGetIdx(void *pKey)
{
    return abs(*(int *)pKey);
}

static void *peaHashUtGetKey(void *pKv)
{
    return (void *)(&((PeaUtHashKv_t *)pKv)->key);
}

static void peaHashLsitTableTest(void)
{
    PeaHashTable_t *pTable = peaHashTableCreate(PEA_HASH_BUCKET_CAP, peaHashUtKeyCmp, peaHashUtGetIdx, peaHashUtGetKey);
    UT_ASSERT(pTable != NULL);

    {
        int kvNum = 2001;
        for (int idx = 0; idx < kvNum; idx++) {
            PeaUtHashKv_t *pKv = (PeaUtHashKv_t *)malloc(sizeof(*pKv));
            UT_ASSERT(pKv != NULL);
            pKv->key = idx;
            pKv->val = idx;
            int rc = pTable->pfKvPut(pTable, pKv);
            UT_ASSERT(rc == 0);
        }
        for (int idx = 0; idx < kvNum; idx++)
        {
            PeaUtHashKv_t *pKv = pTable->pfKvGet(pTable, &idx);
            UT_ASSERT(pKv != NULL);
            UT_ASSERT(pKv->val == pKv->key);
        }
        for (int idx = 0; idx < kvNum; idx++)
        {
            PeaUtHashKv_t *pKv = pTable->pfKvPick(pTable, &idx);
            UT_ASSERT(pKv != NULL);
            UT_ASSERT(pKv->val == pKv->key);
            free(pKv);
        }
    }
    pTable->pfDestroy(pTable);
}

UtCase_t gPeaHashTableSuit[] = {
    {"peaHashLsitTableTest", peaHashLsitTableTest},
    {NULL, NULL}
};
